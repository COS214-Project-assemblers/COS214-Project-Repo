/* Ane' Burger 24565068 */

import React, { useState } from "react";
import { Link } from "react-router";

const Suggestions = ({ onCancel }) => {

    return (
        <div className="suggestBody">
            <div id="suggest-board">
                <img alt="suggest-board" src="/assets/images/suggest-board.svg" width="50"/>
            </div>

            <div id="suggestGrid">
                <div>
                    <p>Plant_one</p>
                </div>

                <div>
                    <p>Plant_two</p>
                </div>

                <div>
                    <p>Plant_three</p>
                </div>

                <div>
                    <p>Plant_four</p>
                </div>

                <div>
                    <p>Plant_five</p>
                </div>
            </div>



            <button id="suggest" onClick={onCancel}><img alt="suggest" src="/assets/images/suggest-button.svg" width="50"/></button>
        </div>
    );
}

export default Suggestions;