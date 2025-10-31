/* Ane' Burger 24565068 */

import React, { useState, useEffect } from "react";
import PlantInfoCard from "./PlantInfoCard";

const SoilGrid = () => {
    const [isOpen, setIsOpen] = useState(false);
    const [plants, setPlants] = useState([]);  // greenhouse array
    const [selected, setSelected] = useState(null);
    
    const toggle = () => {
        setIsOpen((isOpen) => !isOpen);
    }

    const loadGreenhouse = async () => {
        try {
        const res = await fetch('/api/greenhouse');
        const data = await res.json();
        setPlants(Array.isArray(data.greenhouse) ? data.greenhouse : []);
        } catch (e) { /* ignore */ }
    };

    useEffect(() => {
        loadGreenhouse();
        const handler = () => loadGreenhouse();
        window.addEventListener('greenhouse:refresh', handler);
        return () => window.removeEventListener('greenhouse:refresh', handler);
    }, []);

    const onPlantClick = (plant) => {
        console.log('Seedling clicked:', plant?.id);
        setSelected(plant);
        setIsOpen(true);
    };

    const slots = Array.from({ length: 9 }, (_, i) => {
        const plant = plants[i];
        return (
        <React.Fragment key={i}>
            <img alt={`soil${i+1}`} id={`soil${i+1}`} src="/assets/images/soil.svg" width="50" />
            {plant && (
            <div id={`plant${i+1}`}>
                <img onClick={() => onPlantClick(plant)} alt={`plant${i+1}`} src="/assets/images/seedling.svg" width="50" style={{ cursor: 'pointer', pointerEvents: 'auto' }}/>
            </div>
            )}
        </React.Fragment>
        );
    });

    return (
        <div className="soilBody">
            <div id="soilGrid">
                {slots}
                {/* <img alt="soil1" id="soil1" src="/assets/images/soil.svg" width="50"/>
                
                <div id="plant1"><img onClick={toggle} alt="plant1" src="/assets/images/seedling.svg" width="50"/></div>
                
                <img alt="soil2" id="soil2" src="/assets/images/soil.svg" width="50"/>
                <img alt="soil3" id="soil3" src="/assets/images/soil.svg" width="50"/>
                <img alt="soil4" id="soil4" src="/assets/images/soil.svg" width="50"/>
                <img alt="soil5" id="soil5" src="/assets/images/soil.svg" width="50"/>
                <img alt="soil6" id="soil6" src="/assets/images/soil.svg" width="50"/>
                <img alt="soil7" id="soil7" src="/assets/images/soil.svg" width="50"/>
                <img alt="soil8" id="soil8" src="/assets/images/soil.svg" width="50"/>
                <img alt="soil9" id="soil9" src="/assets/images/soil.svg" width="50"/> */}
            </div>
            {isOpen && <PlantInfoCard onCancel={toggle} plant={selected} />}
        </div>
    );
}

export default SoilGrid;