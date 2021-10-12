

function getItems() {
    db.collection("items").get().then((querySnapshot) => {
        let items = [];

        querySnapshot.forEach((doc) => {

            // console.log(`${doc.id} => ${doc.data()}`);
            items.push({
                id: doc.data().id,
                image: doc.data().Image,
                name: doc.data().Make,
                rating: doc.data().Ratings,
                price: doc.data().Price
            })

            
        });
      
        return items;
        

        

        
    }).then((items)=> {
        generateItems(items)
        console.log(items);

    }) 

    // generateItems(items)

}

function generateItems(items) {
    var itemsHTML = "";
    items.forEach((item) => 
    {
        itemsHTML += `
        <div class="main-product ">
                            <div class=" ml-5 product-image w-48 h-52 bg-white rounded-lg p-4">
                                <img class=" w-full h-full object-contain"
                                    src="${item.Image}"
                                    alt="Loading">
                            </div>
                            <div class=" ml-5 product-name font-bold text-gray-700 mt-3 ">
                            ${item.Name}
                            </div>
                            <div class="ml-5 product-rating font-bold text-gray-700">
                                ⭐⭐⭐⭐${item.Ratings}
                            </div>
                            <div class="ml-5 product-price font-bold text-gray-700">
                              $ ${item.Image}
                            </div>
                            <div
                                class="mt-2 add bg-yellow-400 flex justify-center items-center text-white rounded-lg h-10 w-43 hover:bg-yellow-600 cursor:pointer ml-3 mr-3 p-3">
                                Add To Cart</div>
                        </div>
        `
    })

    document.querySelector(".main-section-products").innerHTML=itemsHTML;


}

getItems();

