/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link } from "react-router";

const Suggestions = ({ onCancel, offered = [], onSelect }) => {
    const [selectedIdx, setSelectedIdx] = useState(-1);

    const choose = () => {
        if (selectedIdx < 0) return onCancel?.();
        const choice = offered[selectedIdx];
        onSelect?.(choice);
    };

    const imgForDifficulty = (d) => {
      const dd = String(d || '').toLowerCase();
      if (dd === 'easy') return '/assets/images/easy.svg';
      if (dd === 'medium') return '/assets/images/medium.svg';
      return '/assets/images/hard.svg';
    };

    return (
        <div className="suggestBody">
            <div id="suggest-board">
                <img alt="suggest-board" src="/assets/images/suggest-board.svg" width="50"/>
            </div>

            <div id="suggestGrid">
                {offered.slice(0,5).map((p, i) => (
                  <div key={i}
                    id={`suggest-${i+1}`}
                    onClick={() => setSelectedIdx(i)}
                    style={{ cursor: 'pointer' }}
                    title={`${p.variety} (${p.category})`} >
                    <p>{p.variety} <span>({p.category})</span></p>

                    <img className={p.difficulty} alt={p.difficulty || 'difficulty'} src={imgForDifficulty(p.difficulty)} width="50"/>
                    {selectedIdx === i ? (
                      <img className="selected" alt="selected" src="/assets/images/selected.svg" width="50"/>
                    ) : (
                      <img className="not-selected" alt="not-selected" src="/assets/images/not-selected.svg" width="50"/>
                    )}
                  </div>
                ))}
            </div>

            <div style={{ display: 'flex', gap: 12, justifyContent: 'center' }}>
              <button id="suggest" onClick={choose}>
                <img alt="suggest" src="/assets/images/suggest-button.svg" width="50"/>
              </button>
              <button onClick={onCancel}>
                <img alt="cancel-suggest" src="/assets/images/cancel.svg" width="50"/>
              </button>
            </div>
        </div>
    );
}

export default Suggestions;