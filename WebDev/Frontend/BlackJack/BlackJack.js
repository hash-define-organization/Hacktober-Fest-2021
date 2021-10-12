let player = {
    name: "Bet",
    chips: 200
}

let cards = []
let sum = 0
let hasBlackJack = false
let isAlive = false
let message = ""
let messageEl = document.getElementById("message-el")
let sumEl = document.getElementById("sum-el")
let cardsEl = document.getElementById("cards-el")
let playerEl = document.getElementById("player-el")
let temp=0

playerEl.textContent = player.name + ": $" + player.chips

function getRandomCard() {
    let randomNumber = Math.floor( Math.random()*13 ) + 1
        return randomNumber
}

function startGame() {
    isAlive = true
    let firstCard = getRandomCard()
    let secondCard = getRandomCard()
    cards = [firstCard, secondCard]
    if(firstCard >10 && secondCard>10)
    {
        sum=20
    }
    else if(firstCard>10)
    {
        if(secondCard===1)
        {sum=10+11
        }
        sum=10+secondCard
    }
    else if(secondCard>10)
    {
        if(firstCard===1)
        {sum=10+11
        }
        sum=10+firstCard
    }
    else{
        if(firstCard===1&&secondCard===1)
        {
            sum=22
        }
        else if(firstCard===1)
        {
            sum=11+secondCard
        }
        else if(secondCard===1)
        {
            sum=11+firstCard
        }
        sum=firstCard+secondCard
    }
    for (let i = 2; i < temp; i++) {
        // cardsEl.textContent +="Cards/"+cards[i]+".png"
        var randomNumberSource1= ""
        var image1 = document.querySelectorAll("img")[i]
        image1.setAttribute("src", randomNumberSource1)
    }
    renderGame()
}

function renderGame() {
    // cardsEl.textContent = "Cards: "
    for (let i = 0; i < cards.length; i++) {
        // cardsEl.textContent +="Cards/"+cards[i]+".png"
        var randomNumberSource1= "Cards/"+cards[i]+".png"
        var image1 = document.querySelectorAll("img")[i]
        image1.setAttribute("src", randomNumberSource1)
    }
    
    sumEl.textContent = "Sum: " + sum
    if (sum <= 20) {
        message = "Do you want to draw a new card?"
    } else if (sum === 21) {
        message = "You've got Blackjack! Money is doubled!!😱😱"
        hasBlackJack = true
        player.chips*=2
        playerEl.textContent = player.name + ": $" + player.chips
    } else {
        message = "You're out of the game!"
        isAlive = false
        player.chips=0
        playerEl.textContent = player.name + ": $" + player.chips
        temp=cards.length
    }
    messageEl.textContent = message
}


function newCard() {
    if (isAlive === true && hasBlackJack === false) {
        let card = getRandomCard()
        sum += card
        cards.push(card)
        renderGame()        
    }
}
