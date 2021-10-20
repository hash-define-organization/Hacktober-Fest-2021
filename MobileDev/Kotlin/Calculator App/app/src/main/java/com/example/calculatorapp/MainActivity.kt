package com.example.calculatorapp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.view.Window
import android.widget.Button
import android.widget.Toast
import androidx.core.content.ContextCompat
import kotlinx.android.synthetic.main.activity_main.*
import java.lang.ArithmeticException

class MainActivity : AppCompatActivity() {

    var lastNumeric: Boolean = false
    var lastDot: Boolean = false
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val window : Window = this@MainActivity.window
        window.statusBarColor = ContextCompat.getColor(this@MainActivity, R.color.silver)
    }

    fun onEqual(view : View)
    {
        if(lastNumeric){
            var CalcValue = CalculatorTxt.text.toString()
            var prefix = ""

            try {
                if(CalcValue.startsWith("-")){
                    prefix = "-"
                    CalcValue = CalcValue.substring(1)//remove first element from string

                }
                if(CalcValue.contains("-")){
                    // we need to split up the string
                    val splitValue = CalcValue.split("-")
                    var one = splitValue[0]
                    var two = splitValue[1]
                    if(!prefix.isEmpty()){
                        one = prefix + one
                    }
                    CalculatorTxt.text = removeZeros((one.toDouble() - two.toDouble()).toString())
                }
                else if(CalcValue.contains("+")){
                    // we need to split up the string
                    val splitValue = CalcValue.split("+")
                    var one = splitValue[0]
                    var two = splitValue[1]
                    if(!prefix.isEmpty()){
                        one = prefix + one
                    }
                    CalculatorTxt.text = removeZeros((one.toDouble() + two.toDouble()).toString())
                }
                else if(CalcValue.contains("/")){
                    // we need to split up the string
                    val splitValue = CalcValue.split("/")
                    var one = splitValue[0]
                    var two = splitValue[1]
                    if(!prefix.isEmpty()){
                        one = prefix + one
                    }
                    CalculatorTxt.text = removeZeros((one.toDouble() / two.toDouble()).toString())
                }
                else if(CalcValue.contains("*")){
                    // we need to split up the string
                    val splitValue = CalcValue.split("*")
                    var one = splitValue[0]
                    var two = splitValue[1]
                    if(!prefix.isEmpty()){
                        one = prefix + one
                    }
                    CalculatorTxt.text = removeZeros((one.toDouble() * two.toDouble()).toString())
                }

            }
            catch(e : ArithmeticException){
                e.printStackTrace()
            }
        }
    }

    private fun removeZeros(result : String):String{
        var value = result
        if(result.contains(".0")){
            value = result.substring(0,result.length-2)
        }
        return value
    }

    fun onDigit(view : View)
    {
        if(getString(R.string.btn0).equals(CalculatorTxt.text.toString()))
        {
            CalculatorTxt.text = ""
        }
        CalculatorTxt.append((view as Button).text)
        lastNumeric = true
    }

    fun onClear(view : View)
    {
        CalculatorTxt.text = getString(R.string.btn0)
        lastNumeric = false
        lastDot = false
    }

    fun onDecimalPoint(view : View)
    {
        if(lastNumeric && !lastDot)
        {
            CalculatorTxt.append(".")
            lastNumeric = false
            lastDot = true
        }
    }

    fun onOperator(view : View)
    {
        if(lastNumeric && !isOperatorAdded(CalculatorTxt.text.toString())){
            CalculatorTxt.append((view as Button).text)
            lastNumeric = false
            lastDot = false
        }
    }
    private fun isOperatorAdded(value: String): Boolean {
        return if(CalculatorTxt.text.startsWith("-"))
        {
            false
        }
        else{
            value.contains("/") || value.contains("*") ||
                    value.contains("+") || value.contains("-")
        }
    }
}