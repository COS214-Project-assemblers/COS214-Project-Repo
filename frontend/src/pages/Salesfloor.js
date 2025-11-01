/* Ane' Burger 24565068 */

import React, { useState } from "react";
import Navbar from '../components/Navbar';
import Suggestions from '../components/Suggestions';

const Salesfloor = () => {
    const [isOpen, setIsOpen] = useState(false);

    const toggle = () => {
        setIsOpen((isOpen) => !isOpen);
    }

    return (
        <div className="salesfloorBody">
            <Navbar/>

            {/* <div id="ignorant-customer">
                <img alt="ignorant" src="/assets/images/ignorant.png" width="50"/>
            </div> */}

            {/* <div id="medium-customer">
                <img alt="medium" src="/assets/images/medium-customer.png" width="50"/>
            </div> */}

            <div id="greenfinger-customer">
                <img alt="greenfinger" src="/assets/images/greenfinger.png" width="50"/>
            </div>

            <div id="dialogue-board">
                <img alt="dialogue-board" src="/assets/images/dialogue-board.svg" width="50"/>
            </div>

            <div id="customer-name">
                <p>Customer_name</p>
            </div>

            <div id="customer-dialogue">
                <p>"Sup, just give me one of those plant things..."</p>
            </div>

            <button id="next" onClick={toggle}><img alt="next" src="/assets/images/next.svg" width="50"/></button>
            {isOpen && <Suggestions onCancel={toggle} />}

            <div id="wood"><img alt="wood" src="/assets/images/wood.svg" width="50"/></div>
        </div>
    );
}

export default Salesfloor;