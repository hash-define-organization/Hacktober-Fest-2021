import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:http/http.dart' as http;

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  runApp(MaterialApp(
    home: MyLinuxApp(),
    debugShowCheckedModeBanner: false,
  ));
}

late String command;
late String ip;
var data;
var v;

class MyLinuxApp extends StatefulWidget {
  @override
  _MyLinuxAppState createState() => _MyLinuxAppState();
}

Color hexToColor(String code) {
  return new Color(int.parse(code.substring(1, 7), radix: 16) + 0xFF000000);
}

class _MyLinuxAppState extends State<MyLinuxApp> {
  var firebase = FirebaseFirestore.instance;

  check() async {
    var url = Uri.http("$ip", "/cgi-bin/all.py", {"x": command});
    var response = await http.get(url);
    await firebase.collection("linux").add({
      'ip': ip,
      'command': command,
      'output': "${response.body}",
    });
    setState(() {
      data = response.body;
    });
    print(data);
  }

  get() async {
    var g = await firebase.collection("linux").get();
    v = g.docs[0].data();
    print(v);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: new Container(
          padding: const EdgeInsets.all(20.0),
          color: Colors.black54,
          child: Column(
            children: [
              new Container(
                height: 145,
                width: 140,
                decoration: BoxDecoration(
                  image: const DecorationImage(
                    image: AssetImage('assets/linux.png'),
                    fit: BoxFit.cover,
                  ),
                ),
              ),
              new Container(
                child: new Center(
                    child: new Column(children: [
                  new Padding(padding: EdgeInsets.only(top: 5.0)),
                  new Text(
                    'Li-Ter Mobile',
                    style: new TextStyle(
                        color: hexToColor("#4f030e"), fontSize: 30.0),
                  ),
                  new Padding(padding: EdgeInsets.only(top: 25.0)),
                  new TextFormField(
                    decoration: new InputDecoration(
                      labelText: "Enter Host IP",
                      labelStyle: TextStyle(
                        color: Colors.black,
                      ),
                      fillColor: Colors.redAccent,
                      border: new OutlineInputBorder(
                        borderRadius: new BorderRadius.circular(25.0),
                        borderSide:
                            const BorderSide(color: Colors.black, width: 2.0),
                      ),
                      prefixIcon: Icon(
                        Icons.laptop_chromebook,
                        color: Colors.black,
                        size: 26,
                      ),
                    ),
                    validator: (val) {
                      if (val!.length == 0) {
                        return "IP cannot be Empty.";
                      } else {
                        return null;
                      }
                    },
                    keyboardType: TextInputType.number,
                    style: new TextStyle(
                      fontFamily: "Poppins",
                    ),
                    onChanged: (value) {
                      ip = (value);
                    },
                  ),
                  Container(
                    height: 10.0,
                  ),
                  new TextFormField(
                    decoration: new InputDecoration(
                      labelText: "Enter Linux Command",
                      labelStyle: TextStyle(
                        color: Colors.black,
                      ),
                      fillColor: Colors.greenAccent,
                      border: new OutlineInputBorder(
                        borderRadius: new BorderRadius.circular(25.0),
                        borderSide: new BorderSide(color: Colors.blue),
                      ),
                      prefixIcon: Icon(
                        Icons.comment,
                        color: Colors.black,
                        size: 26,
                      ),
                    ),
                    validator: (val) {
                      if (val!.length == 0) {
                        return "Command Cannot be Empty.";
                      } else {
                        return null;
                      }
                    },
                    keyboardType: TextInputType.text,
                    style: new TextStyle(
                      fontFamily: "Poppins",
                    ),
                    onChanged: (value) {
                      command = (value);
                    },
                  ),
                  ElevatedButton(
                    child: Text('Submit'),
                    onPressed: () {
                      print("results...");
                      check();
                    },
                    style: ElevatedButton.styleFrom(
                      primary: Colors.redAccent,
                      onPrimary: Colors.black,
                      onSurface: Colors.deepPurple[300],
                    ),
                  ),
                  new Padding(padding: EdgeInsets.only(top: 10.0)),
                  Container(
                    width: double.infinity,
                    decoration: BoxDecoration(
                      border: Border.all(
                        color: Colors.blueGrey,
                        width: 2,
                      ),
                    ),
                    child: Card(
                      child: Text(
                        data ?? "Wait for the result ...",
                      ),
                    ),
                  ),
                ])),
              ),
            ],
          )),
    );
  }
}
