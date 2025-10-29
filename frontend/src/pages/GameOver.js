/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link } from "react-router";

const GameOver = () => {

    return (
        <div className="gameOverBody">
            <div id="game-over-title">
                <img alt="gameOver-title" src="/assets/images/game-over.svg" width="300"/>
            </div>
            <div id="gameOver-buttons-div">
                <Link to="/greenhouse"><button id="new-game-button2"><img alt="new-game-button2" src="/assets/images/New-Game.svg" width="50"/></button></Link>
                <button id="exit-day-button2"><img alt="exit-day-button2" src="/assets/images/exit-game.svg" width="50"/></button>
            </div>
            <img alt="zero-balance" id="zero-balance" src="/assets/images/balance.svg" width="50"/><span id="zero-b-value">0</span>
        </div>
    );
}

export default GameOver;