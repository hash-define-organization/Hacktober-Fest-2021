import React from 'react';
import "./Footer.css";
import { BsShuffle, BsFillPlayCircleFill } from "react-icons/bs";
import { MdSkipPrevious, MdSkipNext } from "react-icons/md";
import { IoRepeat } from "react-icons/io5";
import { FaRegHeart } from "react-icons/fa";

import {
  PlaylistPlay,
  VolumeDown,
} from "@material-ui/icons";
import { Grid, Slider } from "@material-ui/core";



function Footer() {
    return (
      <div className="footer">
        <div className="footer-left">
          <img
            src="https://i1.sndcdn.com/artworks-000206668484-ec0pss-t500x500.jpg"
            alt=""
            className="footer-albumLogo"
          />
          <div className="footer-songInfo">
            <h4>Look At Me!</h4>
            <p>XXXTENTACION</p>
          </div>
          <FaRegHeart className="footer-icon" size={19} />
        </div>
        <div className="footer-center">
          <BsShuffle className="green-icon" size={19} />
          <MdSkipPrevious className="footer-icon" size={19} />
          <BsFillPlayCircleFill
            fontSize="large"
            className="footer-icon"
            size={30}
          />
          <MdSkipNext className="footer-icon" size={19} />
          <IoRepeat className="green-icon" size={19} />
        </div>
        <div className="footer-right">
          <Grid container spacing={2}>
            <Grid item>
              <PlaylistPlay />
            </Grid>
            <Grid item>
              <VolumeDown />
            </Grid>
            <Grid item xs>
              <Slider />
            </Grid>
          </Grid>
        </div>
      </div>
    );
}

export default Footer