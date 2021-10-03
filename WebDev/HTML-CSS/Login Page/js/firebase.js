var firebaseConfig = {
    apiKey: "AIzaSyBBgVvTLJmjjL4e-naTNgXAaFwKIoGFEwk",
    authDomain: "project-1-usersetup.web.app",
    projectId: "project-1-usersetup",
    storageBucket: "project-1-usersetup.appspot.com",
    messagingSenderId: "463333837761",
    appId: "1:463333837761:web:e5cff3cb7b3cbf25d53d40"
};

// var firebaseConfig = {
//     apiKey: "AIzaSyBBgVvTLJmjjL4e-naTNgXAaFwKIoGFEwk",
//     authDomain: "project-1-usersetup.web.app",
//     projectId: "project-1-usersetup",
//     storageBucket: "project-1-usersetup.appspot.com",
//     messagingSenderId: "463333837761",
//     appId: "1:463333837761:web:e5cff3cb7b3cbf25d53d40"
// };

// apiKey = ${{ ServiceWorkerRegistration.API_KEY 

firebase.initializeApp(firebaseConfig);
export default firebase;