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
                    <img onClick={() => onPlantClick(plant)} alt={`plant${i+1}`} src="/assets/images/seedling.svg" width="50" 
                        style={{ cursor: 'pointer', pointerEvents: 'auto' /* e.g. , filter: 'hue-rotate(280deg) saturate(150%)'  */ }}/>
                </div>
            )}
        </React.Fragment>
        );
    });

    /*  ================= Inline CSS needed to change the hue of the Plant images on the SoilGrid ==================== 
    
        If the plant has the following:
            - health score above 50% (green): do not add anything to the plant's img tag in the React Fragment above

            - health score of 20% to 50% (orange): add the following in the style attribute of the img tag: 
                    filter: "hue-rotate(321deg) saturate(100%)"

            - health score below 20% (red):
                    filter: "hue-rotate(280deg) saturate(150%)"

            - health score at 0%:
                    -> the img tag's src path must change to: /assets/images/Dead-plant.svg 
                    -> and the following must be added to the style attribute: marginTop: '5em'
                    E.g. <img onClick={() => onPlantClick(plant)} alt={`plant${i+1}`} src="/assets/images/Dead-plant.svg" width="50" style={{ cursor: 'pointer', pointerEvents: 'auto', marginTop: '5em' }}/>
    
    */


    return (
        <div className="soilBody">
            <div id="soilGrid">
                {slots}
            </div>
            {isOpen && <PlantInfoCard onCancel={toggle} plant={selected} />}
        </div>
    );
}

export default SoilGrid;