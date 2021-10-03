import {errorObject} from './authentication.js'

// Switch Forms

const signUp = document.getElementById('sign-up'),
    signIn = document.getElementById('sign-in'),
    loginIn = document.getElementById('login-in'),
    loginUp = document.getElementById('login-up')


signUp.addEventListener('click', ()=>{
    // Remove classes first if they exist
    loginIn.classList.remove('block')
    loginUp.classList.remove('none')

    // Add classes
    loginIn.classList.toggle('none')
    loginUp.classList.toggle('block')
})

signIn.addEventListener('click', ()=>{
    // Remove classes first if they exist
    loginIn.classList.remove('none')
    loginUp.classList.remove('block')

    // Add classes
    loginIn.classList.toggle('block')
    loginUp.classList.toggle('none')
})

// Alert Message

const note = document.querySelector('.alert');

function css(element, style) {
  for (const property in style)
      {
          element.style[property] = style[property];
      }
}

function openPopUp()
{
    note.style['display'] = 'block';
    console.log("Open Message");
    css(note, {display: 'block'});
}

function closePopUp()
{
    console.log("Closed Message");
    css(note, {display: 'none'});
}

var loginMessage = () => {
    
    if (Object.keys(errorObject)['length'] === 0)
    {
        document.getElementById('login-message').innerHTML = "Login Successfull";
        var alertMessage = document.getElementById('alert-message');
        alertMessage.classList.remove("danger-alert");
        alertMessage.classList.add("success-alert");
        openPopUp();
    } 
    else if(errorObject)         //If error is there then show red doesnt work now
    {
        var alertMessage = document.getElementById('alert-message');
        alertMessage.classList.remove("success-alert");
        alertMessage.classList.add("danger-alert");
        
        document.getElementById('login-message').innerHTML = errorObject['errorMessageKey'];
        openPopUp();
    }
}

function myFunction() {
    // Get the snackbar DIV
    var x = document.getElementById("snackbar");
  
    // Add the "show" class to DIV
    x.className = "show";
  
    // After 3 seconds, remove the show class from DIV
    setTimeout(function(){ x.className = x.className.replace("show", ""); }, 3000);
  }


document.querySelector('.close').addEventListener("click", closePopUp);
document.getElementById('show-snackbar').addEventListener("click", myFunction);

export {loginMessage};