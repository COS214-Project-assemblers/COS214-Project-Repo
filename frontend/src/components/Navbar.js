/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link } from "react-router";

const Navbar = () => {

    return (
        <div className="navbarBody">
            <div id="nav">
                <button id="quit-game-button"><img alt="quit-game-button" src="/assets/images/Quit-Game.svg" width="50"/></button>
                <Link to="/salesfloor"><button id="go-to-sales"><img alt="go-to-sales" src="/assets/images/go-to-sales.svg" width="50"/></button></Link>
                <img alt="balance" id="balance" src="/assets/images/balance.svg" width="50"/><span id="b-value">200</span>
            </div>
        </div>
    );
}

export default Navbar;