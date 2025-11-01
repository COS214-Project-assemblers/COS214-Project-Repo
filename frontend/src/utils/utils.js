import gameConfig from "../data/GameConfig.json"

export function getCategoriesCount() {
    let result = {};

    let plantCategories = gameConfig["plantCategories"];

    for (const [category, varieties] of Object.entries(plantCategories)) {
        const varietyArray = Object.entries(varieties).map(([varietyName, data]) => ({
            name: varietyName,
            costPrice: data.costPrice,
            salePrice: data.salePrice
        }));

        result[category] = [varietyArray, varietyArray.length];
    }

    result.numCategories = Object.keys(plantCategories).length;

    return result;
}

export function getInitialPrices() {
    let plantCategories = gameConfig["plantCategories"]; 

    const initialPrices = Object.fromEntries(
        Object.entries(plantCategories).map(([category, varieties]) => [
            category,
            Object.values(varieties).map(v => v.costPrice)
        ])
    );

    return initialPrices;
}

export async function buyPlant(variety, quantity) {
    const res = await fetch('/api/buy-plants', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({"plant": variety, "numToBuy": quantity}),
        });

        const data = await res.json();
        if (!res.ok) {
            alert(data.error || 'Failed to buy ' + variety);
            return false;
        }

        return true;
}