/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link, useNavigate } from "react-router-dom";

const GameOver = () => {
    const navigate = useNavigate();
    const newGame = async () => {
        try {
            const res = await fetch('/api/new-game', { method: 'POST' });
            if (!res.ok) {
                const err = await res.json().catch(() => ({}));
                console.error('New game failed', err);
                alert('Failed to create new game.');
                return;
            }
            console.log('New game created successfully');
            navigate('/');
        } catch (e) {
            console.error(e);
            alert('Network error creating new game.');
        }
    };

    const exitGame = async () => {
        try {
            const res = await fetch('/api/exit-game', { method: 'POST' });
            if (!res.ok) {
                const err = await res.json().catch(() => ({}));
                console.error('Exit game failed', err);
                alert('Failed to exit game.');
                return;
            }
            console.log('Game exited successfully');
            navigate('/gameover');
        } catch (e) {
            console.error(e);
            alert('Network error exiting the game.');
        }
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