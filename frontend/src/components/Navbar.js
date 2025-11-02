/* Ane' Burger 24565068 */

import React, { useState, useEffect } from "react";
import { Link, useNavigate } from "react-router-dom";
import { openDB, updateDBRecord, getPlantRecord, initSocket, getAllRecords} from "../utils/db"

const Navbar = () => {
  const navigate = useNavigate();
  const [balance, setBalance] = useState(0);
  const [salesCount, setSalesCount] = useState(0);
  const [busy, setBusy] = useState(false);
  const [canGoSales, setCanGoSales] = useState(false);

  useEffect(() => {
    const load = async () => {
      try {
        const [balRes, sfRes] = await Promise.all([
          fetch('/api/balance'),
        ]);
        const balData = await balRes.json();
        setBalance(balData.balance ?? 0);
        openDB().then(() => getAllRecords()).then((res) => {
          res.forEach((el) => {
          });
        });

      } catch (e) { console.log(e); }
    };
    load();

    const onBalanceUpdate = (e) => {
      if (typeof e.detail === 'number') setBalance(e.detail);
      else load();
    };
    const onSalesfloorRefresh = () => {
      openDB().then(() => getAllRecords()).then((res) => {
        let diedOrSellable = true;
        let count = 0;
          res.forEach((el) => {
            if (!el.state && !el.died)
              diedOrSellable = false;
            if (el.state)
              count++;
          });
          setSalesCount(count);
          setCanGoSales(diedOrSellable && count > 0);
          console.log("Can go sales: " + diedOrSellable);
        });
    };

    window.addEventListener('balance:update', onBalanceUpdate);
    window.addEventListener('salesfloor:refresh', onSalesfloorRefresh);

    return () => {
      window.removeEventListener('balance:update', onBalanceUpdate);
      window.removeEventListener('salesfloor:refresh', onSalesfloorRefresh);
    };
  }, []);

  const goToSalesfloor = async () => {
    if (busy) return;
    setBusy(true);
    try {
      const resClear = await fetch('/api/clear-customers');
      const resIg = await fetch('/api/add-customers', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json' 
        },
        body: JSON.stringify({"customerType": "ignorant", "numToAdd": 1})
      });

      const resAv = await fetch('/api/add-customers', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({"customerType": "average", "numToAdd": 1})
      });

      const resGr = await fetch('/api/add-customers', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json' 
        },
        body: JSON.stringify({"customerType": "greenfinger", "numToAdd": 1})
      });

      navigate('/salesfloor');
    } catch (e) {
      console.error(e);
      alert('Network error.');
    } finally {
      setBusy(false);
    }
  };

  const exitGame = async () => {
    try {
      const res = await fetch('/api/exit-game', { method: 'GET' });
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

  // const canGoSales = salesCount > 8 && !busy; // just to check if the sales floor has >8 plants and if customers are already being created

  return (
    <div className="navbarBody">
      <div id="nav">
        <button id="quit-game-button" onClick={exitGame}><img alt="quit-game-button" src="/assets/images/Quit-Game.svg" width="50" /></button>

        {/* navigate to salesfloor only when the salesfloor array has >8 plants otherwise disabled */}
        <button id="go-to-sales" onClick={goToSalesfloor}
          disabled={!canGoSales} style={{ opacity: canGoSales ? 1 : 0.5, cursor: canGoSales ? 'pointer' : 'not-allowed' }} >
          <img alt="go-to-sales" src="/assets/images/go-to-sales.svg" width="50" />
        </button>

        <img alt="balance" id="balance" src="/assets/images/balance.svg" width="50" /><span id="b-value">{balance}</span>
      </div>
    </div>
  );
}

export default Navbar;