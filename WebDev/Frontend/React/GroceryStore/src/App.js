import './App.css';
import React,{ useEffect, useState } from 'react';
import List from './List';
import {BiDownload} from 'react-icons/bi'

const getStorage = () =>{
  const list = localStorage.getItem('list');
  if(list){
    return JSON.parse(list)
  }
  else{
    return []
  }
}

function App() {
  const [items, setitems] = useState(getStorage);
  const [name, setname] = useState('');
  const [isedit, setisedit] = useState(false);
  const [Id, setId] = useState('');


  function remove(e) {
    const itemId = e.currentTarget.parentNode.getAttribute("data-key");
    const filteredItems = items.filter((item) => item.id !== itemId);
    setitems(filteredItems);
    setisedit(false)
    setname('')
  }

  function input(e){
    setname(e.target.value)
    
  }

  function editItem(e) {
    setisedit(true)
    const itemId = e.currentTarget.parentNode.getAttribute("data-key");
    setId(itemId)
    items.map((item) => {
      if(item.id === itemId){
        setname(item.title)
      }
    })
  }

  function edit(e) {
    e.preventDefault()
    setitems(items.map((item) => {
      if (item.id === Id){
        return {...item,title: name}
      }
      return item
    }))

    setname('')
    setisedit(false)
  }

  function submit(e){
    e.preventDefault();
    if (name !== ''){
    const data = {id: new Date().getTime().toString() , title : name}
    setitems([data,...items])
    setname('')}
  }
  useEffect(() => {
    localStorage.setItem('list',JSON.stringify(items))
  }, [items])
  
  function download() {
    const text = "     GROCERY LIST \n**********************\n\n" + items.map((item,index) => `${index + 1}. ${item.title}`).join('\n') + "\n\n**********************\n"
    const element = document.createElement('a');
    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
    element.setAttribute('download', 'Grocery_Items.txt');

    element.style.display = 'none';
    document.body.appendChild(element);

    element.click();

    document.body.removeChild(element);
}

  return (
    <div className="container">
      <h2>Grocery Items <span className="badge"> {Object.keys(items).length} </span> </h2>
      <span className="btndwnld"><button onClick={download}><BiDownload /></button></span>
      <section className="input">
        <form onSubmit={isedit?edit:submit}>
          <input type="text" value={name} onChange={input} placeholder="e.g. oil" target/>
          <button type="submit">{isedit?'Edit Item':'Add Item'}</button>
        </form>
      </section>
      
      <List items={items} remove={remove} editItem={editItem}/>
      
      <button className="clear" onClick={() => {
        setitems([])
        setisedit(false)
        setname('')
      }}>
      Clear items</button>
    </div>
  );
}

export default App;
