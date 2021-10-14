import React from 'react';
import "./Login.css";
import { loginUrl } from './spotify';


function Login() {
    return (
      <div className="login">
        {/* <img
          src="https://s22.q4cdn.com/540910603/files/design/Spotify_Logo_White.png"
          alt="logo"
        ></img> */}

        <a href={loginUrl}>LOGIN</a>
      </div>
    );
}

export default Login
