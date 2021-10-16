import React from 'react'
import "./SidebarOption.css";

function SidebarOption({heading,Icon}) {
    return (
      <div className="sidebarOption">
        <div style={{ color: "#fff" }}>
          {Icon && (
            <Icon className="sidebarOption-icon" size={29} ></Icon>
          )}
        </div>
        {Icon ? <h4>{heading}</h4> : <p>{heading}</p>}
      </div>
    );
}


export default SidebarOption;

// function PlaylistOption({ heading, Icon }) {
//   return (
//     <div className="playlistOption">
//       {Icon && (
//         <Icon className="playlistOption-icon" size={29} color="#fff"></Icon>
//       )}
//       {Icon ? <h4>{heading}</h4> : <p>{heading}</p>}
//     </div>
//   );
// }