/* Ane' Burger 24565068 */

import React, { useState, useEffect } from "react";
import { Link } from "react-router";

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
                    <p>Category: {info.category}</p>
                    <p>Variety: {info.variety}</p>
                    <p>Health Score: {info.healthScore?.toFixed?.(1) ?? info.healthScore}</p>
                    <p>Pruning Level: {info.pruningLevel?.toFixed?.(1) ?? info.pruningLevel}</p>
                    <p>Water Level: {info.waterLevel?.toFixed?.(1) ?? info.waterLevel}</p>
                    <p>Fertilizer Level: {info.fertilizerLevel?.toFixed?.(1) ?? info.fertilizerLevel}</p>

                    <p>Cost Price: {info.costPrice}</p>
                    <p>Sell Price: {info.sellPrice}</p>

                    <p id="maturity">Maturity: <span id="mature-span">{info.maturity}</span></p>
                  </>
                )}
            </div>

            <div id="info-buttons">
                <button id="cancel-info" onClick={onCancel}><img alt="cancel-info" id="cancel-info" src="/assets/images/cancel-info.svg" width="50"/></button>
                <button id="move-to" disabled={disabled}><img alt="move-to" id="move-to-sales" src="/assets/images/move-to-sales.svg" width="50"/></button>
            </div>
        </div>
    );
}

export default PlantInfoCard;