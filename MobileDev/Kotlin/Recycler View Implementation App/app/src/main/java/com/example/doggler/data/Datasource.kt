package com.example.doggler.data

import com.example.doggler.R
import com.example.doggler.dog.Dog

class Datasource {
    fun loadDogs(): List<Dog>{
        return listOf<Dog>(
                Dog(R.drawable.tzeitel,R.string.name1,R.string.age1,R.string.Hobby1),
                Dog(R.drawable.leroy,R.string.name2,R.string.age2,R.string.Hobby2),
                Dog(R.drawable.frankie,R.string.name3,R.string.age3,R.string.Hobby3),
                Dog(R.drawable.nox,R.string.name4,R.string.age4,R.string.Hobby4),
                Dog(R.drawable.bella,R.string.name5,R.string.age5,R.string.Hobby5),
                Dog(R.drawable.faye,R.string.name6,R.string.age6,R.string.Hobby6)
        )
    }
}
