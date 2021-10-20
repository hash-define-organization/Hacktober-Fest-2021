import React from 'react'
import "./Sidebar.css";
import SidebarOption from './SidebarOption';
import { MdHomeFilled } from "react-icons/md";
import { AiOutlineSearch } from "react-icons/ai";
import { BiLibrary, BiHeartSquare } from "react-icons/bi";
// import { GoDiffAdded } from "react-icons/go";
import { VscDiffAdded } from "react-icons/vsc";
import { CgMediaPodcast } from "react-icons/cg";



import { useDataLayerValue } from './DataLayer';
// import { color } from '@mui/system';


function Sidebar() {
  const[{ playlists },dispatch] = useDataLayerValue();
    return (
      <div className="sidebar">
        <img
          className="Sidebar-Logo"
          src="https://www.freepnglogos.com/uploads/spotify-logo-png/spotify-logo-horizontal-white-20.png"
          alt=""
        />
        
        <SidebarOption Icon={MdHomeFilled} heading="Home" />
        <SidebarOption Icon={AiOutlineSearch} heading="Search" />
        <SidebarOption
          Icon={BiLibrary}
          heading=" Your Library"
          background-color="#fff"
        />
        <br />
        <br />
        <SidebarOption Icon={ VscDiffAdded } heading="Add Playlist" />
        <SidebarOption Icon={BiHeartSquare} heading="Liked Songs" />
        <SidebarOption Icon={CgMediaPodcast} heading="Your Episodes" />
        {/* <strong className="sidebar-title">PLAYLISTS</strong> */}
        <hr />

        {playlists?.items?.map((playlist) => (
          <SidebarOption heading={playlist.name} />
        ))}
      </div>
    );
}

export default Sidebar;

