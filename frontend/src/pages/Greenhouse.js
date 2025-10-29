/* Ane' Burger 24565068 */

import React, { useState } from "react";
import Navbar from '../components/Navbar';
import SoilGrid from '../components/SoilGrid';
import BuyPlants from '../components/BuyPlants';

const Greenhouse = () => {

    return (
        <div className="greenhouseBody">
            <Navbar/>
            <SoilGrid/>
            <BuyPlants/>
        </div>
    );
}

export default Greenhouse;