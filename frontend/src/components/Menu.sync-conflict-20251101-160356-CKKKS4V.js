/* Ane' Burger 24565068 */

import React, { useState, useEffect, useMemo } from "react";
import { getCategoriesCount, getInitialPrices, buyPlant } from "../utils/utils.js";

const Menu = ({ onCancel }) => {
    const [flower, setFlower] = useState([0, 0, 0]);
    const [succulent, setSucculent] = useState([0, 0, 0]);
    const [tree, setTree] = useState([0, 0, 0]);

    const [used, setUsed] = useState(0);
    const [capacity, setCapacity] = useState(9);
    const [balance, setBalance] = useState(0);
    const [prices, setPrices] = useState(getInitialPrices());
    const available = Math.max(0, capacity - used);

    useEffect(() => {
        const load = async () => {
            try {
                const [gh, bal] = await Promise.all([
                    fetch('/api/greenhouse/plants').then(r => r.json()),
                    fetch('/api/balance').then(r => r.json())
                ]);
                setUsed(JSON.parse(gh.data).length > 0 ?? 0);
                setBalance(bal.balance ?? 0);
            } catch (e) { /* ignore */ }
        };
        load();
    }, []);

    const onChangeArr = (arr, setter, idx) => (e) => {
        const v = Math.max(0, Math.min(9, Number(e.target.value) || 0));
        const copy = [...arr]; copy[idx] = v; setter(copy);
    };

    const totalSelected = useMemo(
        () => flower.reduce((a,b)=>a+b,0) + succulent.reduce((a,b)=>a+b,0) + tree.reduce((a,b)=>a+b,0),
        [flower, succulent, tree]
    );

    const totalCost = useMemo(() => {
        const sum = (arr, priceArr) => arr.reduce((s, qty, i) => s + (Number(qty)||0) * (priceArr?.[i] || 0), 0);
        return sum(flower, prices.flower) + sum(succulent, prices.succulent) + sum(tree, prices.tree);
    }, [flower, succulent, tree, prices]);

    const onBuy = async () => {
        if (totalSelected === 0) {
            alert('Please select at least one plant or Cancel instead.');
            return;
        }
        if (totalSelected > available) {
            alert(`You can only buy ${available} more plant(s).`);
            return;
        }
        if (totalCost > balance) {
            alert(`Insufficient balance. You need ${totalCost}, available ${balance}.`);
            return;
        }

        let categoriesCount = getCategoriesCount();
        for (let i = 0; i < flower.length; i++) {
            if (flower[i] > 0) {
                await buyPlant(categoriesCount.flowers[0][i].name, flower[i]);
            }
        }

        for (let i = 0; i < succulent.length; i++) {
            if (succulent[i] > 0) {
                await buyPlant(categoriesCount.succulents[0][i].name, succulent[i]);
            }
        }

        for (let i = 0; i < tree.length; i++) {
            if (tree[i] > 0) {
                await buyPlant(categoriesCount.trees[0][i].name, tree[i]);
            }
        }
        
        // setUsed(data.used ?? used);
        // setBalance(data.balance ?? balance);
        
        window.dispatchEvent(new CustomEvent('greenhouse:refresh'));
        // window.dispatchEvent(new CustomEvent('balance:update', { detail: data.balance }));
        setFlower([0,0,0]); setSucculent([0,0,0]); setTree([0,0,0]); // Reset selections after successful purchase
        onCancel();
        // } catch (e) {
        // console.error(e);
        // alert('Network error while buying plants.');
        // }
    };

    return (
        <div className="menuBody">
            <div id="menuDiv">
                <img alt="menu" id="menu" src="/assets/images/Menu.svg" width="50"/>
            </div>

            {/* <p id="capacity">Greenhouse capacity: {used} / {capacity} </p> */}

           <div id="flowerAmountGrid">
                <input type="number" id="num1" min="0" max="9" value={flower[0]} onChange={onChangeArr(flower, setFlower, 0)} /> {/* Rose */}
                <input type="number" id="num2" min="0" max="9" value={flower[1]} onChange={onChangeArr(flower, setFlower, 1)} /> {/* Tulip */}
                <input type="number" id="num3" min="0" max="9" value={flower[2]} onChange={onChangeArr(flower, setFlower, 2)} /> {/* Daisy */}
            </div>

            <div id="succAmountGrid">
                <input type="number" id="num4" min="0" max="9" value={succulent[0]} onChange={onChangeArr(succulent, setSucculent, 0)} /> {/* Cactus */}
                <input type="number" id="num5" min="0" max="9" value={succulent[1]} onChange={onChangeArr(succulent, setSucculent, 1)} /> {/* Aloe */}
                <input type="number" id="num6" min="0" max="9" value={succulent[2]} onChange={onChangeArr(succulent, setSucculent, 2)} /> {/* Jade */}
            </div>

            <div id="treeAmountGrid">
                <input type="number" id="num7" min="0" max="9" value={tree[0]} onChange={onChangeArr(tree, setTree, 0)} /> {/* Lemon */}
                <input type="number" id="num8" min="0" max="9" value={tree[1]} onChange={onChangeArr(tree, setTree, 1)} /> {/* Apple */}
                <input type="number" id="num9" min="0" max="9" value={tree[2]} onChange={onChangeArr(tree, setTree, 2)} /> {/* Oak */}
            </div>

            <p id="totalBalance">{totalCost}</p>

            <button id="buy" onClick={onBuy}><img alt="buy" src="/assets/images/Buy.svg" width="50"/></button>
            <button id="cancelBuy" onClick={onCancel}><img alt="cancel" id="cancel-cross" src="/assets/images/cancel.svg" width="50"/></button>
        </div>
    );
}

export default Menu;