package com.example.doggler.adapter

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.doggler.R
import com.example.doggler.dog.Dog

class ItemAdapter(private val context: Context,
                  private val dataset: List<Dog>
                  ) : RecyclerView.Adapter<ItemAdapter.ItemViewHolder>() {
    class ItemViewHolder(private val view: View):RecyclerView.ViewHolder(view){
        val dogImg: ImageView = view.findViewById(R.id.dog_img)
        val dogName: TextView = view.findViewById(R.id.dog_name)
        val dogAge: TextView = view.findViewById(R.id.dog_age)
        val dogHobby: TextView = view.findViewById(R.id.dog_hobby)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ItemViewHolder {
        //here we are creating a new view on which we are inflating list_item layout
        val adapterLayout = LayoutInflater.from(parent.context).inflate(R.layout.list_item,parent,false)
        return ItemViewHolder(adapterLayout)
    }

    override fun onBindViewHolder(holder: ItemViewHolder, position: Int) {
        val item = dataset[position]
        holder.dogImg.setImageResource(item.imageResourceID)
        holder.dogName.text = context.resources.getString(item.name)
        holder.dogAge.text = context.resources.getString(item.age)
        holder.dogHobby.text = context.resources.getString(item.Hobbies)
    }

    override fun getItemCount(): Int {
        return dataset.size
    }
}