/* Ane' Burger 24565068 */

import React, { useState, useEffect } from "react";
import PlantInfoCard from "./PlantInfoCard";
import { openDB, updateDBRecord, getPlantRecord, initSocket, getAllRecords} from "../utils/db"

const SoilGrid = () => {
    const [isOpen, setIsOpen] = useState(false);
    const [plants, setPlants] = useState([]);  // greenhouse array
    const [selected, setSelected] = useState(null);
    
    const toggle = () => {
        setIsOpen((isOpen) => !isOpen);
    }

    // add the correct colour or show correct img for the plants based on maturity/health score
    const getPlantImgProps = (plant) => {
        const hs = Number(plant?.healthScore ?? 100);
        const baseStyle = { cursor: 'pointer', pointerEvents: 'auto' };

        // 0% health -> dead plant image
        if (hs <= 0) { // hs == health score
            return {
                src: '/assets/images/Dead-plant.svg',
                style: { ...baseStyle, marginTop: '5em' },
            };
        }

        // Mature plants use mature image that has a star added
        if (plant?.maturity === 'Sellable') {
            return {
                src: '/assets/images/mature.svg',
                style: baseStyle,
            };
        }

        // Seedling image with color based on health score
        let style = { ...baseStyle };
        if (hs < 20) {
            style.filter = 'hue-rotate(280deg) saturate(150%)'; // red
        } else if (hs <= 50) {
            style.filter = 'hue-rotate(321deg) saturate(100%)'; // orange
        } // >50: green, no filter

        return {
            src: '/assets/images/seedling.svg',
            style,
        };
    };

    const loadGreenhouse = async () => {
        try {
        const res = await fetch('/api/greenhouse/plants');
        const data = await res.json();
        openDB().then(() => getAllRecords()).then((res) => setPlants(res));
        // setPlants(Array.isArray(JSON.parse(data.data)) ? JSON.parse(data.data) : []);
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
                    {(() => {
                        const { src, style } = getPlantImgProps(plant);
                        return (
                          <img onClick={() => onPlantClick(plant)} alt={`plant${i+1}`}
                                src={src} width="50" style={style} />
                        );
                    })()}
                </div>
            )}
        </React.Fragment>
        );
    });

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