firebase.auth().onAuthStateChanged(function(user) 
{
    if (user) 
    {
        document.querySelector('.email').innerText = user["email"];
        console.log(user);
        console.log(user["email"]);
        console.log(user["displayName"]);
        console.log(user["emailVerified"]);     
    }
    else
    {
        // const queryString = window.location.search;
        // const urlParams = new URLSearchParams(queryString);
        window.location.href = "./index.html"
        console.log(user);
    }
});

function signOut()
{
    firebase.auth().signOut().then(() => {
      // Sign-out successful.
      }).catch((error) => {
      // An error happened.
    });
}

function myFunction() {
    // Get the snackbar DIV
    var x = document.getElementById("snackbar");
  
    // Add the "show" class to DIV
    x.className = "show";
  
    // After 3 seconds, remove the show class from DIV
    setTimeout(function(){ x.className = x.className.replace("show", ""); }, 3000);
  }

document.getElementById('signout').addEventListener("click", signOut); //Signup
document.getElementById('show-snackbar').addEventListener("click", myFunction);