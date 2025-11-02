/* Ane' Burger 24565068 */

import React, { useState, useEffect, useMemo } from "react";
import Navbar from '../components/Navbar';
import Suggestions from '../components/Suggestions';
import { openDB, deletePlantRecord, getAllRecords, getPlantRecord} from "../utils/db"
import { useNavigate } from "react-router-dom"; 
                                                                // result is accept/reject and then exit is the acceptExit/rejectExit
const DIALOG_ORDER = ['introduction', 'preferences', 'recommendations', 'result', 'exit'];
const Salesfloor = () => {
    const [isOpen, setIsOpen] = useState(false);
    const [customers, setCustomers] = useState([]);
    const [currentIdx, setCurrentIdx] = useState(0);
    const [stage, setStage] = useState('introduction'); 
    const [resultAccepted, setResultAccepted] = useState(null);
    const [numPlantsLeft, setNumPlants] = useState(0);

    const current = customers[currentIdx];
    const navigate = useNavigate();

    const toggle = () => {
        setIsOpen((isOpen) => !isOpen);
    }

    const imgForType = (type) => {
      switch (type) {
        case 'ignorant':
          return { src: '/assets/images/ignorant.png', style: { width: '41em', marginLeft: '1em' } };
        case 'average':
          return { src: '/assets/images/medium-customer.png', style: { width: '24em', marginLeft: '6em' } };
        default: 
          return { src: '/assets/images/greenfinger.png', style: { width: '18em', marginLeft: '11em' } };
      }
    };

    const loadCustomers = async () => {
      try {
        const resGet = await fetch('/api/customers');
        const data = await resGet.json();
        console.log(JSON.parse(data.customersJson));
        setCustomers(Array.isArray(JSON.parse(data.customersJson)) ? JSON.parse(data.customersJson) : []);
        setCurrentIdx(0);
        setStage('introduction');
        setResultAccepted(null);

        await openDB().then(() => getAllRecords()).then((plants) => {
          // console.log(plants);
          let numPlants = 0;
          plants.forEach((p) => {
            if (!p.died) ++numPlants;
          });
          setNumPlants(numPlants);
        });
      } catch (e) { console.error(e); }
    };

    useEffect(() => {
      loadCustomers();
    }, []);

    const next = async () => {
      if (!current) return;
      if (stage === 'introduction') setStage('preferences');
      else if (stage === 'preferences') setStage('recommendations');
      else if (stage === 'recommendations') setIsOpen(true); // open Suggestions component
      else if (stage === 'result') setStage('exit');
      else if (stage === 'exit') {
        const nextIndex = currentIdx + 1;   // move to next customer
        if (nextIndex < customers.length && numPlantsLeft > 0) {
          const nextCustomer = customers[nextIndex];
          const offeredCopy = (
          await Promise.all(
            (nextCustomer.offeredPlants || []).map(async (orig) => {
              try {
                await openDB();
                const rec = await getPlantRecord(orig.id); 
                if (!rec) return null; 
                return rec ? { ...orig, ...rec } : orig;
              } catch {
                return orig;
              }
            })
          )
        ).filter(Boolean);

          console.log("Offered copy");
          console.log(offeredCopy);
          const newCustomers = [...customers];
          newCustomers[nextIndex] = { ...nextCustomer, offeredPlants: offeredCopy };
          setCustomers(newCustomers);
          setCurrentIdx(nextIndex);
          setStage('introduction');
          setResultAccepted(null);
        } else {
          navigate('/endofday');
        }
      }
    };

    const onSuggested = async (selection) => {
      setIsOpen(false);       // selection: { variety, category, acceptable }

      if (!selection) return;

      const accepted = String(selection.acceptable).toLowerCase() === 'yes'; // Decide accept/reject from 'acceptable'
      setResultAccepted(accepted);
      setStage('result');

      if (accepted) {
        try {
          const res = await fetch('/api/salesfloor/make-sale', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ id: selection.id})
          });
          const data = await res.json();
          if (res.ok) {
            openDB().then(() => deletePlantRecord(selection.id)).then((success) => console.log(success));
            setNumPlants(numPlantsLeft - 1);
            window.dispatchEvent(new CustomEvent('balance:update', { detail: data.balance }));
            window.dispatchEvent(new CustomEvent('salesfloor:refresh'));
          } else {
            console.warn('Sell failed:', data.error);
          }
        } catch (e) {
          console.error('Sell failed:', e);
        }
      }
    };

    // to get the dialogue and change the button's text
    const dialogue = useMemo(() => {
      if (!current) return { text: '', label: 'Next' };
      if (stage === 'introduction') return { text: current.introduction, label: 'Next' };
      if (stage === 'preferences') return { text: current.preferences, label: 'Next' };
      if (stage === 'recommendations') return { text: current.recommendations, label: 'Suggest' };
      if (stage === 'result') return {
        text: resultAccepted ? current.accept : current.reject,
        label: 'Next'
      };
      if (stage === 'exit') return {
        text: resultAccepted ? current.acceptExit : current.rejectExit,
        label: 'Next'
      };
      return { text: '', label: 'Next' };
    }, [current, stage, resultAccepted]);

    return (
        <div className="salesfloorBody">
            <Navbar/>

            {current && (
              <>
                <div id="greenfinger-customer">
                    {(() => {
                      const { src, style } = imgForType(current.type);
                      return <img alt="customer" src={src} style={style} />;
                    })()}
                </div>

                <div id="dialogue-board">
                    <img alt="dialogue-board" src="/assets/images/dialogue-board.svg" width="50"/>
                </div>

                <div id="customer-name">
                    <p>{current.name}</p>
                </div>

                <div id="customer-dialogue">
                    <p>{dialogue.text}</p>
                </div>

                {dialogue.label === 'Suggest' ? (
                  <button id="next" onClick={() => setIsOpen(true)}>
                    <img alt="suggest" src="/assets/images/suggest-button.svg" width="50"/>
                  </button>
                ) : (
                  <button id="next" onClick={next}>
                    <img alt="next" src="/assets/images/next.svg" width="50"/>
                  </button>
                )}
              </>
            )}
            {isOpen && current && (

              <Suggestions onCancel={() => setIsOpen(false)} offered={current.offeredPlants} onSelect={onSuggested} />
            )}

            <div id="wood"><img alt="wood" src="/assets/images/wood.svg" width="50"/></div>
        </div>
    );
}

export default Salesfloor;