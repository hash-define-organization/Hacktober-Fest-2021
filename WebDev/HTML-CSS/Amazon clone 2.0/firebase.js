var firebaseConfig = {
    apiKey: "AIzaSyAanATbzCqSdBNXNc57x7vIluU3nSepqW4",
    authDomain: "clone-two-2f38e.firebaseapp.com",
    projectId: "clone-two-2f38e",
    storageBucket: "clone-two-2f38e.appspot.com",
    messagingSenderId: "330136802106",
    appId: "1:330136802106:web:2fd38d1fd7975e00517603",
    measurementId: "G-RW0DPBJKZZ"
  };
  // Initialize Firebase
  firebase.initializeApp(firebaseConfig);
  firebase.analytics();

  var db = firebase.firestore();