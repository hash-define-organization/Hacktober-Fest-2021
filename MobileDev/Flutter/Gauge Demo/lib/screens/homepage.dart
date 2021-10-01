import 'package:flutter/material.dart';

import '/screens/linear_gauge.dart';
import '/screens/radial_gauge.dart';

class HomePage extends StatelessWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      //The Scaffold is designed to be a top level container for a MaterialApp
      //contains many properties such as appBar, body, routes, actions.
      appBar: AppBar(
        title: const Text(
            'Flutter Gauge'), //Text Widget which renders text onto the screen
      ),
      body: Container(
        margin: const EdgeInsets.fromLTRB(5, 50, 5,
            0), //EdgeInsets.fromLTRB means  margin from left,top ,right, bottom
        padding: const EdgeInsets.all(
            20), //EdgeInsets.all means  margin from all sides
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [
            ElevatedButton(
              onPressed: () {
                //Navigator class is used for managing routing to other screen
                //The navigator manages a stack of Route objects and provides two ways for managing the stack,
                //the imperative API Navigator.push and Navigator.pop.
                Navigator.of(context).pushNamed(RadialGaugeScreen.routeName);
              },
              child: const Text('Radial Gauge'),
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.of(context).pushNamed(LinearGaugeScreen.routeName);
              },
              child: const Text('Linear Gauge'),
            ),
          ],
        ),
      ),
    );
  }
}
