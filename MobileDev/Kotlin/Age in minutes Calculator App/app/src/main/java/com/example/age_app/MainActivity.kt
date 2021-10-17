package com.example.age_app

import android.app.DatePickerDialog
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_main.*
import java.text.SimpleDateFormat
import java.util.*

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        bttnDatepikr.setOnClickListener{view ->
            clickDatepikr(view)
        }
    }

    fun clickDatepikr(view: View){

        val myCalender = Calendar.getInstance()
        val year = myCalender.get(Calendar.YEAR)
        val month = myCalender.get(Calendar.MONTH)
        val day = myCalender.get(Calendar.DAY_OF_MONTH)
        val dpd = DatePickerDialog(
            this,
            DatePickerDialog.OnDateSetListener {
                    view, selYear, selMonth, selDate ->
                val selectedDate = "$selDate/${selMonth+1}/$selYear"
                dateTxt.setText(selectedDate)
                //Important*********************************************************
                val sdf = SimpleDateFormat("dd/MM/yyyy",Locale.ENGLISH)
                val theDate = sdf.parse(selectedDate)
                val selectedDateMin = theDate!!.time / 60000
                val currentDate = sdf.parse(sdf.format(System.currentTimeMillis()))
                val currentDateMin = currentDate!!.time / 60000
                val differenceInMinutes = currentDateMin - selectedDateMin
                ageDisp.setText(differenceInMinutes.toString())
            },year,month,day)

        dpd.datePicker.setMaxDate(Date().time - 86400000)
        dpd.show()

    }
}