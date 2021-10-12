import "./App.css";

import Navbar from "./components/Navbar";

import Textform from "./components/Textform";

import React from "react";
import { BrowserRouter as Router, Switch, Route } from "react-router-dom";

import { useState } from "react";
function App() {
  const [mode, setmode] = useState("light");

  const togglemode = () => {
    if (mode === "light") {
      setmode("dark");
      document.body.style.backgroundColor = "black";
      document.title = "Text editor:dark mode";
    } else {
      setmode("light");
      document.body.style.backgroundColor = "white";
      document.title = "Text editor:light mode";
    }
  };

  return (
    <>
      <Router>
        <Navbar mode={mode} togglemode={togglemode} />

        <Switch>
          <Route path="/">
            <Textform heading=" Write Text Below " mode={mode} />
          </Route>
        </Switch>
      </Router>
    </>
  );
}

export default App;
