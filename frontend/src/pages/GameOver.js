/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link, useNavigate } from "react-router-dom";

const GameOver = () => {
    const navigate = useNavigate();
    const newGame = async () => {
        try {
            navigate('/');
        } catch (e) {
            console.error(e);
            alert('Network error creating new game.');
        }
    };

    const exitGame = async () => {
        navigate('/');
    };

    return (
        <div className="gameOverBody">
            <div id="game-over-title">
                <img alt="gameOver-title" src="/assets/images/game-over.svg" width="300"/>
            </div>
            <div id="gameOver-buttons-div">
                <button id="new-game-button2" onClick={newGame}><img alt="new-game-button2" src="/assets/images/New-Game.svg" width="50"/></button>
                <button id="exit-day-button2" onClick={exitGame}><img alt="exit-day-button2" src="/assets/images/exit-game.svg" width="50"/></button>
            </div>
            {/* <img alt="zero-balance" id="zero-balance" src="/assets/images/balance.svg" width="50"/><span id="zero-b-value">0</span> */}
        </div>
    );
}

export default GameOver;