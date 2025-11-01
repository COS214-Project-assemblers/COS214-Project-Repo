/* Ane' Burger 24565068 */

import React, { useState, useEffect } from "react";
// import { Link } from "react-router";

const PlantInfoCard = ({ onCancel, plant }) => {
    const [info, setInfo] = useState(null);
    const [loading, setLoading] = useState(false);

    useEffect(() => {
        if (!plant?.id) return;
        const load = async () => {
            setLoading(true);
            try {
                const res = await fetch(`/api/plants/${plant.id}`);
                const data = await res.json();
                if (res.ok) setInfo(data);
                else console.error('Failed to load plant info', data);
            } catch (e) {
                console.error(e);
            } finally {
                setLoading(false);
            }
        };
        load();
    }, [plant?.id]);

    const moveToSales = async () => {
        if (!info) return;
        try {
            const res = await fetch(`/api/plants/${info.id}/move-to-sales`, { method: 'POST' });
            const data = await res.json();
            if (!res.ok) {
                alert(data.error || 'Failed to move plant to salesfloor');
                return;
            }
            console.log('Moved plant to salesfloor:', data.plant);
            window.dispatchEvent(new CustomEvent('greenhouse:refresh'));
            window.dispatchEvent(new CustomEvent('salesfloor:refresh'));
            onCancel();
        } catch (e) {
            console.error(e);
            alert('Network error moving plant.');
        }
    };

    const disabled = (info?.maturity !== 'Sellable');

    return (
        <div className="plantInfoBody">
            <div id="info-title-div">
                <img alt="Info-title" src="/assets/images/plant-info.svg" width="300"/>
            </div>

            <div id="info-board-div">
                <img alt="Info-board" src="/assets/images/Info-board.svg" width="300"/>
            </div>

            <div id="plantInfoGrid">
                {loading && <p>Loading...</p>}
                {!loading && info && (
                  <>
                    <p><span className="field">Category:</span> {info.category}</p>
                    <p><span className="field">Variety:</span> {info.variety}</p>
                    <p><span className="field">Health Score:</span> {info.healthScore ?? info.healthScore}</p>
                    <p><span className="field">Pruning Level:</span> {info.pruningLevel ?? info.pruningLevel} / 3</p>
                    <p><span className="field">Water Level:</span> {info.waterLevel ?? info.waterLevel}</p>
                    <p><span className="field">Fertilizer Level:</span> {info.fertilizerLevel ?? info.fertilizerLevel}</p>

                    <p><span className="field">Cost Price:</span> {info.costPrice}</p>
                    <p><span className="field">Sell Price:</span> {info.sellPrice}</p>

                    <p id="maturity">
                      Maturity: <span id="mature-span" style={{ color: (info?.maturity === 'Sellable') ? '#089108' : 'red' }}>
                        {info.maturity}
                      </span>
                    </p>
                  </>
                )}
            </div>

            <div id="info-buttons">
                <button id="cancel-info" onClick={onCancel}><img alt="cancel-info" id="cancel-info" src="/assets/images/cancel-info.svg" width="50"/></button>
                <button id="move-to" onClick={moveToSales} disabled={disabled}><img alt="move-to" id="move-to-sales" src="/assets/images/move-to-sales.svg" width="50" disabled={disabled}/></button>
            </div>
        </div>
    );
}

export default PlantInfoCard;