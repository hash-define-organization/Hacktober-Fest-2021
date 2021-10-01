import 'package:flutter/material.dart';

import 'package:syncfusion_flutter_gauges/gauges.dart';

//Note it will be stateful as we're changing the values in gauge
//Stateful widgets are useful when we need to re-render
//in order to show changed data
class RadialGaugeScreen extends StatefulWidget {
  const RadialGaugeScreen({Key? key}) : super(key: key);

  static const routeName =
      '/radial-gauge-screen'; //routeName is for using Navigator.of().pushNamed('routeName')

  @override
  _RadialGaugeScreenState createState() => _RadialGaugeScreenState();
}

class _RadialGaugeScreenState extends State<RadialGaugeScreen> {
  double radialGaugeValue = 0; //value of radial gauge

  @override
  Widget build(BuildContext context) {
    Size deviceSize = MediaQuery.of(context)
        .size; //deviceSize will hold meta information about device size using MediaQuery.of(context).size
    //we can make use of it in order to make responsive apps
    return Scaffold(
      appBar: AppBar(
        title: const Text('Radial Gauge'),
      ),
      body: Column(
        children: [
          //this SizedBox will hold the radial gauge
          SizedBox(
            height: deviceSize.height * 0.5,
            width: double.infinity,
            child: SfRadialGauge(
              //The Radial Gauge
              title: const GaugeTitle(
                //GaugeTitle is the title of gauge which can be
                //anything like, speedometer or temperature etc.
                text: 'Flutter-o-meter',
                textStyle: TextStyle(fontSize: 20),
              ),
              //Axes is a circular arc in which values are displayed
              //we can make use of any pointer like needle pointer to point to
              //certain value
              axes: <RadialAxis>[
                RadialAxis(
                  minimum: 0,
                  maximum: 100,
                  ranges: <GaugeRange>[
                    //Ranges help us to visualize where a value falls on axes
                    GaugeRange(
                      startValue: 0,
                      endValue: 25,
                      color: Colors.green,
                    ),
                    GaugeRange(
                      startValue: 25,
                      endValue: 50,
                      color: Colors.yellow,
                    ),
                    GaugeRange(
                      startValue: 50,
                      endValue: 75,
                      color: Colors.orange,
                    ),
                    GaugeRange(
                      startValue: 75,
                      endValue: 100,
                      color: Colors.red,
                    ),
                  ],
                  pointers: <GaugePointer>[
                    //pointers is used to indicate value on the axis
                    NeedlePointer(
                      //there are other types of pointers as well
                      //like range pointer or marker pointer.
                      //or we can have our custom pointers

                      value: radialGaugeValue,

                      enableAnimation:
                          true, //shows animation of pointer as the value changes
                    )
                  ],
                  annotations: <GaugeAnnotation>[
                    GaugeAnnotation(
                      widget: Text(
                        '${radialGaugeValue.toInt()}',
                        style: const TextStyle(
                            fontSize: 20, fontWeight: FontWeight.bold),
                      ),
                      positionFactor: 0.25,
                      angle: 90,
                    )
                  ],
                )
              ],
            ),
          ),
          const Text(
            'Experiment With the Slider',
            style: TextStyle(fontWeight: FontWeight.bold),
          ),
          Row(
            children: [
              Expanded(
                child: Slider(
                  //an other great widget is the Slider widget
                  //Used to select from a range of values.

                  value: radialGaugeValue,
                  min: 0,
                  max: 100,
                  label: '${radialGaugeValue.toInt()}',
                  onChanged: (newRadialGaugeValue) {
                    setState(() {
                      //calling setState() notifies that state of this object has changed
                      //that might effect the user interface
                      //build method of this subtree is called again with the following changes
                      radialGaugeValue = newRadialGaugeValue;
                    });
                  },
                ),
              ),
              Text(
                '${radialGaugeValue.toInt()}/100',
                style: const TextStyle(fontWeight: FontWeight.bold),
              )
            ],
          )
        ],
      ),
    );
  }
}
