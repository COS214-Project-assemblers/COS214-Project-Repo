/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link } from "react-router";

const PlantInfoCard = ({ onCancel }) => {

    return (
        <div className="plantInfoBody">
            <div id="info-title-div">
                <img alt="Info-title" src="/assets/images/plant-info.svg" width="300"/>
            </div>

            <div id="info-board-div">
                <img alt="Info-board" src="/assets/images/Info-board.svg" width="300"/>
            </div>

            <div id="plantInfoGrid">
                <p>Category: </p>
                <p>Variety: </p>
                <p>Health Score: </p>
                <p>Pruning Level: </p>
                <p>Water Level: </p>
                <p>Fertilizer Level: </p>

                <p>Cost Price: </p>
                <p>Sell Price: </p>

                <p>Maturity: </p>
            </div>

            <div id="info-buttons">
                <button id="cancel-info" onClick={onCancel}><img alt="cancel-info" id="cancel-info" src="/assets/images/cancel-info.svg" width="50"/></button>
                <button id="move-to"><img alt="move-to" id="move-to-sales" src="/assets/images/move-to-sales.svg" width="50"/></button>
            </div>
        </div>
    );
}

export default PlantInfoCard;