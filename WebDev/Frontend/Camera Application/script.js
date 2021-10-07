let videoElem = document.querySelector(".video");

let recordBtn = document.querySelector(".record");
let captureImgBtn = document.querySelector(".click-image");
let isRecording = false;
let filterArr = document.querySelectorAll(".filter");
let filterOverlay = document.querySelector(".filter_overlay");
let filterColor = "";
let timings = document.querySelector(".timing");
let counter = 0;
let clearObj;
let scaleLevel = 1;
let plusBtn = document.querySelector(".plus");
let minusBtn = document.querySelector(".minus");

// user ko requirement send karne ke liye
let constraint = {
  audio: true,
  video: true,
};

// represent future recording
let recording = [];
let mediarecordingObjectForCurrStream;

let usermediaPromise = navigator.mediaDevices.getUserMedia(constraint); //"getUserMedia" returns a promise that ask user to allow "constraint"
// stream coming from required
usermediaPromise
  .then(function (stream) {
    videoElem.srcObject = stream; // UI par stream dikhane ke liye

    //To record this stream we have media recorder
    mediarecordingObjectForCurrStream = new MediaRecorder(stream);
    // camera se recording add karwa lenege  recording array mai
    mediarecordingObjectForCurrStream.ondataavailable = function (e) {
      //jab bhi "mediarecordingObjectForCurrStream" mai data available hoga tab yeh func chalega

      recording.push(e.data);
    };

    // download
    mediarecordingObjectForCurrStream.addEventListener("stop", function () {
      //yeh func tab chalega jab bhi rec stop hogi tab yeh rec ko download karega

      let blob = new Blob(recording, { type: "video/mp4" }); // video type is  MIME type(blob converts recording into url )

      addMediaToGallery(blob, "video");
      // const url = window.URL.createObjectURL(blob);
      // let a = document.createElement("a");
      // a.download = "file.mp4";
      // a.href = url;
      // a.click();
      recording = [];
    });
  })
  .catch(function (err) {
    //agar user ne  "constraints"  allow nhi kiye toh catch chalega
    console.log(err);
    alert("please allow both microphone and camera");
  });

recordBtn.addEventListener("click", function () {
  //function tab chalega jab hum record button par click karenge
  if (mediarecordingObjectForCurrStream == undefined) {
    alert("First select the devices");
    return;
  }
  if (isRecording == false) {
    // agar rec start nhi hui toh start kardo
    mediarecordingObjectForCurrStream.start();
    // recordBtn.innerText = "Recording....";
    recordBtn.classList.add("record-animation");
    startTimer();
  } else {
    //agar rec phele se hi start h toh stop kardo
    stopTimer();
    mediarecordingObjectForCurrStream.stop();
    // recordBtn.innerText = "Record";
    recordBtn.classList.remove("record-animation");
  }
  isRecording = !isRecording;
});

captureImgBtn.addEventListener("click", function () {
  //canvas create karenge and then usmai video element paas kar denge becoz video is basically fast moving image frames...so we will capture that particular frame that user pressed click btn
  let canvas = document.createElement("canvas");
  canvas.height = videoElem.videoHeight;
  canvas.width = videoElem.videoWidth;

  let tool = canvas.getContext("2d");
  captureImgBtn.classList.add("capture-animation");

  //zoom in logic(scaling to center)
  tool.scale(scaleLevel,scaleLevel);
  const x=(tool.canvas.width/scaleLevel-videoElem.videoWidth)/2;
  const y=(tool.canvas.height/scaleLevel-videoElem.videoHeight)/2;
  // console.log(x,y)


  tool.drawImage(videoElem, x, y); //captured that particular frame

  //filter logic
  if (filterColor) {
    //agar photo kheeche tab bhi filter lage huye aaye
    tool.fillStyle = filterColor;
    tool.fillRect(0, 0, canvas.width, canvas.height);
  }


  //to download
   let url = canvas.toDataURL();
   addMediaToGallery(url, "img");
  // let a = document.createElement("a");
  // a.download = "file.png";
  // a.href = url;
  // a.click();
  // a.remove();

  setTimeout(function () {
    captureImgBtn.classList.remove("capture-animation");
}, 1000)
});

// filter apply
for (let i = 0; i < filterArr.length; i++) {
  filterArr[i].addEventListener("click", function () {
    // add filter to ui
    filterColor = filterArr[i].style.backgroundColor; //color mai jayega jispar user click karega
    filterOverlay.style.backgroundColor = filterColor;
  });
}

function startTimer() {
  timings.innerText="00:00:00"
  counter=0;
  timings.style.display = "block";//visible kar do UI par
  function fn() {
    let hours = Number.parseInt(counter / 3600);//"Number.parseInt" string ko no. mai convert kardega
    let RemSeconds = counter % 3600;
    let mins = Number.parseInt(RemSeconds / 60);
    let seconds = RemSeconds % 60;
    hours = hours < 10 ? `0${hours}` : hours;
    mins = mins < 10 ? `0${mins}` : mins;
    seconds = seconds < 10 ? `0${seconds}` : seconds;

    timings.innerText = `${hours}:${mins}:${seconds}`;
    counter++;
  }
  clearObj = setInterval(fn, 1000);//har second ke baad fn chalega
}

function stopTimer() {
  timings.style.display = "none";//hide kardo timer ko
  clearInterval(clearObj);
}

minusBtn.addEventListener("click", function () {
  if (scaleLevel > 1) {
    scaleLevel = scaleLevel - 0.1;
    videoElem.style.transform=`scale(${scaleLevel})`;
  }
});


plusBtn.addEventListener("click", function () {
  if (scaleLevel < 3) {
    scaleLevel = scaleLevel + 0.1;
    videoElem.style.transform=`scale(${scaleLevel})`;
  }
})
