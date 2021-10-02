import React from 'react';
import {Header} from './components/Header'; 
import {Balance} from './components/Balance';
import {Expenses} from './components/Expenses'; 
import {List} from './components/List';
import {Addnewtransaction} from './components/Addnewtransaction';

import './App.css';

function App() {
  return (
    <div>
     <Header/>
     <div className="container">
     <Balance/>
     <Expenses/>
     <List/>
     <Addnewtransaction/>
     </div>
    </div>
  );
}

export default App;
