package com.example.birthdaygreet

import android.content.Intent
import android.os.Bundle
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {
    //onCreate() called when activity runs for the first time
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

    }

     //onclick button
    fun createBirthdayCard(view: View) {

         // Toast represents a message displayed as a hint
         // Navigating between the activities (Intent-use)

         val name = nameInput.editableText.toString()
         val intent = Intent(this,BirthdayGreetingActivity::class.java)
         intent.putExtra("name",name)
         startActivity(intent) //in AppCompat

    }

}

