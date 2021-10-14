package com.example.doggler.dog

import androidx.annotation.DrawableRes
import androidx.annotation.StringRes

data class Dog(
        @DrawableRes val imageResourceID:Int,
        @StringRes val name:Int,
        @StringRes val age:Int,
        @StringRes val Hobbies:Int
        )