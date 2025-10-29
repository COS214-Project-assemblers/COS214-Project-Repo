/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link } from "react-router";

const LandingPage = () => {

    return (
        <div className="landingBody">
            {/* <h1>Landing Page</h1> */}
            <div id="title">
                <img alt="greenfingers-title" src="/assets/images/GreenFingers-title.svg" width="300"/>
            </div>
            <div id="landing-buttons-div">
                <Link to="/greenhouse"><button id="new-game-button"><img alt="new-game-button" src="/assets/images/New-Game.svg" width="50"/></button></Link>
                <Link to="/tutorial"><button id="tutorial-button"><img alt="tutorial-button" src="/assets/images/Tutorial.svg" width="50"/></button></Link>
                <button id="exit-button"><img alt="exit-button" src="/assets/images/Exit.svg" width="50"/></button>
            </div>
        </div>
    );
}

export default LandingPage;