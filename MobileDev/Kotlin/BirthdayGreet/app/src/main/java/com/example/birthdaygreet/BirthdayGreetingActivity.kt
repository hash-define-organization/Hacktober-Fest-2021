package com.example.birthdaygreet

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_birthday_greeting.*

class BirthdayGreetingActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_birthday_greeting)

        val name= intent.getStringExtra("name")        //receiving name from previous activity
        birthdayGreeting.text = "Happy Birthday\n$name!"     //id of button birthdayGreeting
    }
}