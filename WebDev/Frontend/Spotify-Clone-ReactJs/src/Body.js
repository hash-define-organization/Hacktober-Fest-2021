import React from 'react'
import "./Body.css"
import Header from "./Header"
import {useDataLayerValue} from "./DataLayer"
import { PlayCircleFilled, Favorite, MoreHoriz } from "@material-ui/icons";
import SongRow from './SongRow';

function Body({spotify}) {
    const [{ discover_weekly }, dispatch] = useDataLayerValue();
    return (
      <div className="body">
        <Header spotify={spotify} />
        <div className="body-info">
          <img src={discover_weekly?.images[0]?.url} alt="Hello" />
          <div className="body-infoText">
            <strong>PLAYLIST</strong>
            <h2>Discover Weekly</h2>
            <p>{discover_weekly?.description}</p>
          </div>
        </div>
        <div className="body-songs">
          <div className="body-icons">
            <PlayCircleFilled className="body-shuffle" />
            <Favorite fontSize="large" />
            <MoreHoriz />
          </div>
          {discover_weekly?.tracks.items.map((item) => (
            <SongRow track={item.track} />
          ))}
        </div>
      </div>
    );
}

export default Body;
