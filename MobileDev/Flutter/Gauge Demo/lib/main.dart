import 'package:flutter/material.dart';

import 'screens/homepage.dart';
import 'screens/radial_gauge.dart';
import 'screens/linear_gauge.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Gauge Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const HomePage(),
      routes: {
        LinearGaugeScreen.routeName: (ctx) => const LinearGaugeScreen(),
        RadialGaugeScreen.routeName: (ctx) => const RadialGaugeScreen()
      },
    );
  }
}
