/* Ane' Burger 24565068 */

import React, { useState, useEffect } from "react";
import { Link, useNavigate } from "react-router-dom";

const Navbar = () => {
    const navigate = useNavigate();
    const [balance, setBalance] = useState(0);

    useEffect(() => {
        const load = async () => {
            try {
                const res = await fetch('/api/balance');
                const data = await res.json();
                setBalance(data.balance ?? 0);
            } catch (e) { console.log(e); }
        };
        load();
        const onBalanceUpdate = (e) => {
          if (typeof e.detail === 'number') setBalance(e.detail);
          else load();
        };
        window.addEventListener('balance:update', onBalanceUpdate);
        return () => window.removeEventListener('balance:update', onBalanceUpdate);
    }, []);

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
        <div className="navbarBody">
            <div id="nav">
                <button id="quit-game-button" onClick={exitGame}><img alt="quit-game-button" src="/assets/images/Quit-Game.svg" width="50"/></button>
                <Link to="/salesfloor"><button id="go-to-sales"><img alt="go-to-sales" src="/assets/images/go-to-sales.svg" width="50"/></button></Link>
                <img alt="balance" id="balance" src="/assets/images/balance.svg" width="50"/><span id="b-value">{balance}</span>
            </div>
        </div>
    );
}

export default Navbar;