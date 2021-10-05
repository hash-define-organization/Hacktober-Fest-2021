let request = indexedDB.open("Camera", 1);
let db;

request.onsuccess = function (e) {
  db = request.result;
};

request.onerror = function (e) {
  console.log("error");
};

request.onupgradeneeded = function (e) {
  db = request.result;
  db.createObjectStore("gallery", { keyPath: "mId" });
};

function addMediaToGallery(data, type) {
  let tx = db.transaction("gallery", "readwrite");
  let gallery = tx.objectStore("gallery");
  gallery.add({ mId: Date.now(), type, media: data });
}

function viewMedia() {
  let body = document.querySelector("body");
  let tx = db.transaction("gallery", "readonly");
  let gallery = tx.objectStore("gallery");
  let req = gallery.openCursor();
  req.onsuccess = function (e) {
    let cursor = req.result;
    if (cursor) {
      if (cursor.value.type == "video") {  //agar video hui 

        let vidContainer = document.createElement("div"); //video-container  ban gya
        vidContainer.setAttribute("data-mId", cursor.value.mId);
        vidContainer.classList.add("gallery-vid-container");
        let video = document.createElement("video"); //video tag bana diya
        vidContainer.appendChild(video); //video tag ko video container se append kar diya

        let deleteBtn = document.createElement("button"); //create delete btn
        deleteBtn.classList.add("gallery-delete-button");
        deleteBtn.innerText = "Delete";
        deleteBtn.addEventListener("click", deleteItem);

        let downloadBtn = document.createElement("button");//create download btn
        downloadBtn.classList.add("gallery-download-button");
        downloadBtn.innerText = "Download";
        downloadBtn.addEventListener("click", donwloadItem);

        vidContainer.appendChild(deleteBtn);//append to video container
        vidContainer.appendChild(downloadBtn);//append to video container

        video.autoplay = true;
        video.controls = true;
        video.loop = true;
        video.src = window.URL.createObjectURL(cursor.value.media);
        body.appendChild(vidContainer);

      } else {      //agar image hui 

        let imgContainer = document.createElement("div");//img-container  ban gya
        imgContainer.setAttribute("data-mId", cursor.value.mId);
        imgContainer.classList.add("gallery-img-container")
        let img = document.createElement("img");//img tag bann gya
        img.src = cursor.value.media;
        imgContainer.appendChild(img);//img tag ko img container ke attach karva diya

        let deleteBtn = document.createElement("button");
        deleteBtn.classList.add("gallery-delete-button");
        deleteBtn.innerText = "Delete";
        deleteBtn.addEventListener("click", deleteItem);

        let downloadBtn = document.createElement("button");
        downloadBtn.classList.add("gallery-download-button");
        downloadBtn.innerText = "Download";
        downloadBtn.addEventListener("click", donwloadItem);

        imgContainer.appendChild(deleteBtn);
        imgContainer.appendChild(downloadBtn);
        body.appendChild(imgContainer);
      }
      cursor.continue();
    }
  };
}


function deleteMediaFromGallery(mId) {
  let tx = db.transaction("gallery", "readwrite");
  let gallery = tx.objectStore("gallery");
  //Typecasting to a number is imp because we have stored Date.now() which gives us a number
  gallery.delete(Number(mId));
}


function deleteItem(e) {
  let mId = e.currentTarget.parentNode.getAttribute("data-mId");
  deleteMediaFromGallery(mId);
  e.currentTarget.parentNode.remove();
}

function donwloadItem(e) {
  let a = document.createElement("a");
  a.href = e.currentTarget.parentNode.children[0].src;
  // checks if the element is video or img so that we can define the extension 
  if (e.currentTarget.parentNode.children[0].nodeName == "IMG") {
    a.download = "image.png";
  } else {
    a.download = "video.mp4";
  }
  a.click()
  a.remove()
}
