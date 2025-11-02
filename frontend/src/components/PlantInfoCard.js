/* Ane' Burger 24565068 */

import React, { useState, useEffect } from "react";
import { openDB, updateDBRecord, getPlantRecord, updateDBCare, getPlantCare } from "../utils/db"

// import { Link } from "react-router";

const PlantInfoCard = ({ onCancel, plant }) => {
    const [info, setInfo] = useState(null);
    const [loading, setLoading] = useState(false);
    const [disabled, setDisabled] = useState(false);
    const [caring, setCaring] = useState(false)
    useEffect(() => {
        console.log(plant);
        if ((plant.id) == "") { return; };
        const load = async () => {
            setLoading(true);
            try {
                await openDB().then(() => getPlantRecord(plant.id)).then((res) => { setInfo(res); if (res.state || res.died) setDisabled(true)});
                await openDB().then(() => getPlantCare(plant.id)).then((res) => {
                    if (res != null) setCaring(true);
                    else setCaring(false);
                })
            } catch (e) {
                console.error(e);
            } finally {
                setLoading(false);
            }
        };
        load();
    }, [plant?.id]);

    const updateInfo = async() => {
        try {
            if (caring) setCaring(false);
            await openDB().then(() => getPlantRecord(plant.id)).then((res) => { setInfo(res)});
        } catch (e) {
            console.error(e);
        } finally {
            setLoading(false);
        }
    }
    window.addEventListener("infocard:update", updateInfo);

    const careForPlant = async () => {
        if (!info) return;
        try {
            const res = await fetch(`/api/greenhouse/plant-care`, { method: 'POST', headers: {'Content-Type': 'application/json'}, body: JSON.stringify({'id': info.id}) });
            await openDB().then(() => updateDBCare({"id": plant.id}));
            const data = await res.json();
            plant.queueCare = true;
            setDisabled(true);
            setCaring(true);
            
            // onCancel?.();

        } catch (e) {
            console.error(e);
            alert("Error while attempting to care for plant");
        }
    }
    return (
        <div className="plantInfoBody">
            <div id="info-title-div">
                <img alt="Info-title" src="/assets/images/plant-info.svg" width="300"/>
            </div>

            <div id="info-board-div">
                <img alt="Info-board" src="/assets/images/Info-board.svg" width="300"/>
            </div>

            <div id="plantInfoGrid">
                {/* {loading && <p>Loading...</p>}
                {!loading && info && ( */}
                  <>
                    <p><span className="field">Category:</span> {info?.category}</p>
                    <p><span className="field">Variety:</span> {info?.variety}</p>
                    <p><span className="field">Health Score:</span> {info?.healthScore ?? '-'}</p>
                    <p><span className="field">Pruning Level:</span> {info?.pruningLevel ?? '-'} / 3</p>
                    <p><span className="field">Water Level:</span> {info?.waterLevel ?? '-'}</p>
                    <p><span className="field">Fertilizer Level:</span> {info?.fertilizerLevel ?? '-'}</p>

                    <p><span className="field">Cost Price:</span> {info?.costPrice}</p>
                    <p><span className="field">Sell Price:</span> {info?.salePrice}</p>

                    <p id="maturity">
                      Maturity: <span id="mature-span" style={{ color: (info?.state) ? '#089108' : 'red' }}>
                        {(info?.state) ? "Sellable (Moved To Sales Floor)" : caring ? "Not Sellable (Queued Caring)" : "Not Sellable"}
                      </span>
                    </p>
                  </>
                {/* )} */}
            </div>

            <div id="info-buttons">
                <button id="cancel-info" onClick={onCancel}><img alt="cancel-info" id="cancel-info" src="/assets/images/cancel-info.svg" width="50"/></button>
                <button id="move-to" onClick={careForPlant} disabled={disabled || info?.state}><img alt="move-to" id="move-to-sales" src="/assets/images/care.svg" width="50"/></button>
            </div>
        </div>
    );
}

export default PlantInfoCard;
