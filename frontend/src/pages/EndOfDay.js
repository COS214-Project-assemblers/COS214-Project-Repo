/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link, useNavigate } from "react-router-dom";

const EndOfDay = () => {
    const navigate = useNavigate();
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
        <div className="endOfDayBody">
            <div id="end-of-day-title">
                <img alt="endOfDay-title" src="/assets/images/end-of-day.svg" width="300"/>
            </div>
            <div id="endOfDay-buttons-div">
                <Link to="/greenhouse"><button id="new-game-button3"><img alt="new-game-button3" src="/assets/images/new-day.svg" width="50"/></button></Link>
                <button id="exit-day-button3" onClick={exitGame}><img alt="exit-day-button3" src="/assets/images/exit-game.svg" width="50"/></button>
            </div>
        </div>
    );
}

export default EndOfDay;