/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link } from "react-router";

const Tutorial = () => {

    return (
        <div className="tutorialBody">
            <Link to="/"><img alt="home" id="home-button" src="/assets/images/Home.svg" width="50"/></Link>
            <div id="tut">
                <img alt="tutorial-board" src="/assets/images/tutorial-board.svg" width="300"/>
                {/* Still need to add the text of the Tutorial component. */}
            </div>
        </div>
    );
}

export default Tutorial;