let screen = document.getElementById('screen')
let screenValue = '';
regex = /[0-9]$/
regex1 = /[0-9]$/
regex2=/[^\+]$/
regex3=/[^\-]$/
buttons = document.querySelectorAll('button')
for (item of buttons) {
    item.addEventListener('click', (e) => {
        buttontext = e.target.innerText;
        console.log(buttontext);
        if (buttontext == "X") {
            if (regex.test(screenValue)) {
                buttontext = "*";
                screen.value = screenValue + "*";
                screenValue = screen.value;
            }
            else if(screenValue.slice((screenValue.length-1), screenValue.length)=="/"){
                screen.value=screenValue.slice(0, (screenValue.length-1))+ "*";
                //console.log(screen.value);
                screenValue=screen.value;
            }
            else {
                screenValue = screenValue;
            }

        }
        else if (buttontext == "/") {
            if (regex1.test(screenValue)) {
                buttontext = "/";
                screen.value = screenValue + "/";
                screenValue = screen.value;
            }
            else if(screenValue.slice((screenValue.length-1), screenValue.length)=="*"){
                screen.value=screenValue.slice(0, (screenValue.length-1))+ "/";
                //console.log(screen.value);
                screenValue=screen.value;
            }
            else {
                screenValue = screenValue;
            }
        }
        else if (buttontext == "+") {
            if (regex2.test(screenValue)) {
                buttontext = "+";
                screen.value = screenValue + "+";
                screenValue = screen.value;
            }
            else {
                screenValue = screenValue;
            }
        }
        else if (buttontext == "-") {
            if (regex3.test(screenValue)) {
                buttontext = "-";
                screen.value = screenValue + "-";
                screenValue = screen.value;
            }
            else {
                screenValue = screenValue;
            }
        }
        else if (buttontext == "c") {
            screenValue = "";
            screen.value = screenValue;
        }
        else if (buttontext == "=") {
            
            try {
                if(isNaN(eval(screenValue))) throw "Error";
            screenValue = eval(screenValue)
            screen.value = screenValue;
              }
              catch(err) {
                screenValue = "Error";
                screen.value=screenValue;
                setTimeout(()=>{
                    screenValue = "";
                    screen.value=screenValue;  
                }, 3000)
              }
            
        }
        else {
            screenValue += buttontext;
            screen.value = screenValue;
        }
    })
}
