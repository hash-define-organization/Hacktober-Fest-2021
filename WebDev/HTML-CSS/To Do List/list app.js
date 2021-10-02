    //declaring and initializing variables
var formList = document.querySelector('form')
var itemList = document.querySelector('.list-group-item')


    //calls event newElement function
formList.addEventListener('submit',newElement);


    //Removes task from list
itemList.addEventListener('click', function (e) {

        //event triggers only when delBtn(containing "delete" class) is pressed
    if(e.target.classList.contains('delete') ) {

            //asks for user confirmation before deletion
        if(confirm('Are You Sure to remove?')) {

                //deletes that item from itemList collection 
            var li = e.target.parentElement
            itemList.removeChild(li)
        }
    }
});

    //add new element in the list
function newElement(e) {

        //prevents default action from happening for event parameter e
    e.preventDefault()

    var newItem = document.querySelector('#input').value
        
        // to do avoid null entries to add to the list
    if (newItem === '') {
        alert("You must write something!");
      } else {  
          // create element , textNode for newItem entered by user ,that is 'li'
    var li = document.createElement('li')

    li.className = 'list-group-item'

    li.appendChild(document.createTextNode(newItem))
         
        //also adding delBtn for this element
    var delBtn = document.createElement('button')

    delBtn.className = 'delete'
    delBtn.appendChild(document.createTextNode('X'))

        //appending delBtn to element having NewItem ,that is 'li'
    li.appendChild(delBtn)

        //appending all this to the original itemList object/collection
    itemList.appendChild(li)
    }
}


