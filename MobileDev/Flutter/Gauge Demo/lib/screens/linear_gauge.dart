import 'package:flutter/material.dart';

import 'package:syncfusion_flutter_gauges/gauges.dart';

//Note it will be stateful as we're changing the values in gauge
//Stateful widgets are useful when we need to re-render
//in order to show changed data
class LinearGaugeScreen extends StatefulWidget {
  const LinearGaugeScreen({Key? key}) : super(key: key);

  static const routeName =
      '/linear-gauge-screen'; //routeName is for using Navigator.of().pushNamed('routeName')

  @override
  _LinearGaugeScreenState createState() => _LinearGaugeScreenState();
}

class _LinearGaugeScreenState extends State<LinearGaugeScreen> {
  double linearGaugeValue = 0; //value of linear gauge

  @override
  Widget build(BuildContext context) {
    Size deviceSize = MediaQuery.of(context)
        .size; //deviceSize will hold meta information about device size using MediaQuery.of(context).size
    //we can make use of it in order to make responsive apps
    return Scaffold(
      appBar: AppBar(
        title: const Text('Linear Gauge'),
      ),
      body: Column(
        children: [
          Container(
            padding: const EdgeInsets.fromLTRB(10, 0, 10, 0),
            height: deviceSize.height * 0.5,
            width: double.infinity,
            child: SfLinearGauge(
              //SfLinearGauge is the class for linear gauge containing many adjustable properties

              minimum: 0,
              //represents the minimum and maximum value of the gauge
              maximum: 100,

              orientation: LinearGaugeOrientation.horizontal,
              // orientation can also be vertical by using the enum LinearGaugeOrientation.vertical

              markerPointers: [
                //markerPointers is the invertedTriangle which is rendered above the bar
                //there are many properties to customize such as its shapeType(a enum)
                //color, size(height and width), border, elevation and much more.
                LinearShapePointer(
                  value: linearGaugeValue,
                  color: Colors.blue,
                )
              ],

              ranges: const [
                //a range is the visual element that helps us visualise where our value lies in
                //the gauge. it takes List<LinearGaugeRange()> class which have its own properties,
                //such as the startValue, endValue and color.
                LinearGaugeRange(
                  startValue: 0,
                  endValue: 25,
                  color: Colors.green,
                ),
                LinearGaugeRange(
                  startValue: 25,
                  endValue: 50,
                  color: Colors.yellow,
                ),
                LinearGaugeRange(
                  startValue: 50,
                  endValue: 75,
                  color: Colors.orange,
                ),
                LinearGaugeRange(
                  startValue: 75,
                  endValue: 100,
                  color: Colors.red,
                ),
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
                  //which can be used to select from either continuous value or discrete set of values
                  value: linearGaugeValue,
                  min: 0,
                  max: 100,
                  label: '${linearGaugeValue.toInt()}',
                  onChanged: (newLinearGaugeValue) {
                    setState(() {
                      //calling setState() notifies that state of this object has changed
                      //that might effect the user interface
                      //build method of this subtree is called again with the following changes
                      linearGaugeValue = newLinearGaugeValue;
                    });
                  },
                ),
              ),
              Text(
                '${linearGaugeValue.toInt()}/100',
                style: const TextStyle(fontWeight: FontWeight.bold),
              )
            ],
          )
        ],
      ),
    );
  }
}
