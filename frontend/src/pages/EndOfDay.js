/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link } from "react-router";

const EndOfDay = () => {

    return (
        <div className="endOfDayBody">
            <div id="end-of-day-title">
                <img alt="endOfDay-title" src="/assets/images/end-of-day.svg" width="300"/>
            </div>
            <div id="endOfDay-buttons-div">
                <Link to="/greenhouse"><button id="new-game-button3"><img alt="new-game-button3" src="/assets/images/new-day.svg" width="50"/></button></Link>
                <button id="exit-day-button3"><img alt="exit-day-button3" src="/assets/images/exit-game.svg" width="50"/></button>
            </div>
        </div>
    );
}

export default EndOfDay;