import './List.css';

import React from 'react';
import {FaTrash,FaEdit} from 'react-icons/fa';

function List({items,remove,editItem}) {
    return (
        <div className="output">
            { ((Object.keys(items).length === 0)?true:false) && <div className="zero"><p>No items in your <em>Grocery List</em> <br />Add items</p></div> }

            {
                items.map((item) =>
                {
                    return (
                        <div className="item" key={item.id} data-key={item.id}>
                            
                            <span className="title">{item.title}</span>                 
                            <button className="delete" onClick={remove}><FaTrash /></button>
                            <button className="edit" onClick={editItem}><FaEdit /></button>
                        </div>
                    );
                })
            }
        </div>
    );
}

export default  List;