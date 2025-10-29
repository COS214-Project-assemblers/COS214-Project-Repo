/* Ane' Burger 24565068 */

import React, { useState } from "react";

const Menu = ({ onCancel }) => {

    return (
        <div className="menuBody">
            <div id="menuDiv">
                <img alt="menu" id="menu" src="/assets/images/Menu.svg" width="50"/>
            </div>

            <div id="flowerAmountGrid">
                <input type="number" id="num1" placeholder="0" min="0" max="9"/>
                <input type="number" id="num2" placeholder="0" min="0" max="9"/>
                <input type="number" id="num3" placeholder="0" min="0" max="9"/>
            </div>

            <div id="succAmountGrid">
                <input type="number" id="num4" placeholder="0" min="0" max="9"/>
                <input type="number" id="num5" placeholder="0" min="0" max="9"/>
                <input type="number" id="num6" placeholder="0" min="0" max="9"/>
            </div>

            <div id="treeAmountGrid">
                <input type="number" id="num7" placeholder="0" min="0" max="9"/>
                <input type="number" id="num8" placeholder="0" min="0" max="9"/>
                <input type="number" id="num9" placeholder="0" min="0" max="9"/>
            </div>

            <p id="totalBalance">60</p>

            <button id="buy"><img alt="buy" src="/assets/images/Buy.svg" width="50"/></button>
            <button id="cancelBuy" onClick={onCancel}><img alt="cancel" id="cancel-cross" src="/assets/images/cancel.svg" width="50"/></button>
        </div>
    );
}

export default Menu;