/* Ane' Burger 24565068 */

import React, { useState } from "react";

const LandingPage = () => {

    return (
        <div className="landingBody">
            {/* <h1>Landing Page</h1> */}
            <img alt="greenfingers-title" id="title" src="/assets/images/GreenFingers-title.svg" width="300"/>
            <div id="landing-buttons-div">
                <button id="new-game-button"><img alt="new-game-button" src="/assets/images/New-Game.svg" width="50"/></button>
                <button id="tutorial-button"><img alt="tutorial-button" src="/assets/images/Tutorial.svg" width="50"/></button>
                <button id="exit-button"><img alt="exit-button" src="/assets/images/Exit.svg" width="50"/></button>
            </div>
        </div>
    );
}

export default LandingPage;