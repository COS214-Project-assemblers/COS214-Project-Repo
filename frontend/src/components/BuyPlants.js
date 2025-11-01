/* Ane' Burger 24565068 */

import React, { useState } from "react";
import Menu from "./Menu";

const BuyPlants = () => {
    const [isOpen, setIsOpen] = useState(false);

    const toggle = () => {
        setIsOpen((isOpen) => !isOpen);
    }

    return (
        <div className="buyPlantsBody">
            <div id="buyPlantsButton">
                <button onClick={toggle} id="buy-plants"><img alt="buy-plants" src="/assets/images/Buy-Plants.svg" width="50"/></button>
                {isOpen && <Menu onCancel={toggle} />}
            </div>
        </div>
    );
}

export default BuyPlants;