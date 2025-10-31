/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link, useNavigate } from "react-router-dom";

const LandingPage = () => {
    const navigate = useNavigate();
    
    const startNewGame = async () => {
        try {
            const res = await fetch('/api/new-game', { method: 'GET' });
            if (!res.ok) {
                const err = await res.json().catch(() => ({}));
                console.error('New game failed', err);
                alert('Failed to start a new game.');
                return;
            }
            console.log('New game started successfully');
            navigate('/greenhouse');
        } catch (e) {
            console.error(e);
            alert('Network error starting a new game.');
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
        <div className="landingBody">
            {/* <h1>Landing Page</h1> */}
            <div id="title">
                <img alt="greenfingers-title" src="/assets/images/GreenFingers-title.svg" width="300"/>
            </div>
            <div id="landing-buttons-div">
                <Link to="/greenhouse"><button id="new-game-button" onClick={startNewGame}><img alt="new-game-button" src="/assets/images/New-Game.svg" width="50"/></button></Link>
                <Link to="/tutorial"><button id="tutorial-button"><img alt="tutorial-button" src="/assets/images/Tutorial.svg" width="50"/></button></Link>
                <button id="exit-button" onClick={exitGame}><img alt="exit-button" src="/assets/images/Exit.svg" width="50"/></button>
            </div>
        </div>
    );
}

export default LandingPage;