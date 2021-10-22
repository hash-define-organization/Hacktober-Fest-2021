import React,{useState} from "react";

export default function Navbar(props) {
    const [text, setText] = useState('');
const handleupclick =()=>{
    console.log("button pressed"+text);
    let newText= text.toUpperCase();
    setText(newText);
   
    
}
const handleloclick =()=>{
    console.log("button pressed"+text);
    let newText= text.toLowerCase();
    setText(newText);
  
}
const handleclearclick =()=>{
    console.log('hey');
    let newText= "";
    setText(newText);
    
}


const fire =(event)=>{
    console.log("hey soniya");
    setText(event.target.value);
}
    return (
        
       <>
      
      
       <div className="container" style= {{color:props.mode==='light'?'black':'white'}} >
          
  
       <h1 className="my-3">{props.heading}</h1>
  <div className="mb-3 my-3 container"  style= {{color:props.mode==='light'?'black':'white'}}>
   <textarea value={text} id="mybox" cols="30" rows="10" className="form-control container" onChange={fire} style= {{backgroundColor:props.mode==='light'?'white':'black',color:props.mode==='light'?'black':'white'}}>

   </textarea>
  </div>
  
<button className="btn btn-primary mx-2 my-1" onClick={handleupclick}>
convert to uppercase
</button>
<button className="btn btn-primary mx-2 my-1" onClick={handleloclick}>
convert to lowercase
</button>
<button className="btn btn-primary mx-2 my-1" onClick={handleclearclick}>
Clear text
</button>

       </div>
       <div className="container" style= {{color:props.mode==='light'?'black':'white'}}>
      <h1>Text Analysis</h1>
      <p> {text.split(" ").filter((element)=>{ return element.length!==0}).length} words {text.length}  charcters</p>
      <p>
          {0.08 * text.split(" ").length} minutes to read
      </p>
    </div>
       </>
    )
}
