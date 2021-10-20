package com.example.weatherforecast

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.inputmethod.EditorInfo
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast
import com.android.volley.Request
import com.android.volley.toolbox.JsonObjectRequest

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val search: Button = findViewById(R.id.buttonSearch)
        val cityName: EditText = findViewById(R.id.cityName)

        search.setOnClickListener {
            loadData()
        }

        cityName.setOnEditorActionListener { _, actionId, _ ->
            if (actionId == EditorInfo.IME_ACTION_SEARCH) {
                loadData()
            }
            false
        }
    }

    private fun loadData() {
        val cityName: EditText = findViewById(R.id.cityName)
        val nameCity = cityName.text.toString()

        val temperature: TextView = findViewById(R.id.textViewTemp)
        val city: TextView = findViewById(R.id.textViewCityName)
        val regionText: TextView = findViewById(R.id.textViewRegion)
        val weatherCondition: TextView = findViewById(R.id.textViewCondition)

        val url =
            "https://api.weatherapi.com/v1/current.json?key=bc3105bbea5c4618b08102701210607&q=$nameCity&aqi=no"

        val jsonObjectRequest = JsonObjectRequest(
            Request.Method.GET, url, null,
            {
                val jsonObject = it.getJSONObject("current")
                val cityTemp = jsonObject.get("temp_c").toString()
                val dummy = jsonObject.getJSONObject("condition")
                val condition = dummy.get("text").toString()
                temperature.text = cityTemp
                weatherCondition.text = condition

                val jsonObject2 = it.getJSONObject("location")
                val cityName = jsonObject2.get("name").toString()
                val region = jsonObject2.get("region").toString()
                city.text = cityName
                regionText.text = region
            },
            {
                Toast.makeText(this, "Invalid City Name", Toast.LENGTH_LONG).show()
            }
        )
        MySingleton.getInstance(this).addToRequestQueue(jsonObjectRequest)
    }
}