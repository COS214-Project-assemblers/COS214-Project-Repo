import express from 'express';
import path from 'path';
import cors from 'cors';
import { XMLHttpRequest } from 'xmlhttprequest';

const app = express();

const HOST = 'localhost';
const PORT = 8000;
const BASE_URL = `http://${HOST}:${PORT}`;

const __dirname = path.resolve();

app.use(cors());
app.use(express.urlencoded({extended: false}));
app.use(express.json());


app.use(express.static(path.join(__dirname, 'frontend', 'public')));


/* ================== MOCK API ENDPOINTS ==================== */

// example mock json object to initialise a game with a balance, 
// empty greenhouse inventory and empty salesfloor inventory
let db = {
  balance: 500,
  greenhouse: [],
  salesfloor: []
};

let nextId = 1;
const CAPACITY = 9;     // capacity of greenhouse (SoilGrid)
const prices = {
  flower: [20, 25, 10], // mock cost prices for each variety displayed in the Menu
  succulent: [15, 20, 10],
  tree: [35, 20, 40],
};

const sellPrices = {    // mock sell prices for each variety
  flower: [36, 45, 18],
  succulent: [27, 36, 18],
  tree: [63, 36, 72],
};

// Mock helper function to create a plant
function createPlant(category, varietyIndex) {
  const varietyNames = {
    flower: ['Rose', 'Tulip', 'Daisy'],
    succulent: ['Cactus', 'Aloe', 'Jade'],
    tree: ['Lemon', 'Apple', 'Oak'],
  };
  const displayCategory = category.charAt(0).toUpperCase() + category.slice(1); // Flower/Succulent/Tree
  const varietyName = varietyNames[category]?.[varietyIndex] ?? `${displayCategory} ${varietyIndex+1}`;

  const costPrice = prices[category]?.[varietyIndex] ?? 0;
  const sellPrice = sellPrices[category]?.[varietyIndex] ?? Math.round(costPrice * 1.8);    
  return {
    id: String(nextId++),
    category: displayCategory,          // string: "Flower" | "Succulent" | "Tree"
    variety: varietyName,               // string: e.g. "Rose"
    healthScore: 100.0,                 // float
    pruningLevel: 0.0,                  // float
    waterLevel: 100.0,                  // float
    fertilizerLevel: 100.0,             // float
    costPrice,                          // int
    sellPrice,                          // int
    maturity: 'Sellable',               // boolean: "Sellable" | "Not-Sellable"
    kind: category,                     // 'flower' | 'succulent' | 'tree'
    varietyIndex,                       
    stage: 'seedling',
  };
}

// Get current balance
app.get('/api/balance', (req, res) => {
  res.json({ balance: db.balance });
});

// // Get the prices of the varieties
// app.get('/api/prices', (req, res) => {
//   res.json(prices);
// });

app.get('/api/cost-prices', (req, res) => {
  res.json(prices);
});

app.get('/api/sell-prices', (req, res) => {
  res.json(sellPrices);
});



// Mock endpoint to initialise the Greenhouse with a capacity of 9 plants and empty inventory
app.get('/api/greenhouse', (req, res) => {
  res.json({
    capacity: CAPACITY,
    used: db.greenhouse.length,
    greenhouse: db.greenhouse,
  });
});

// Get details for a single plant by id
app.get('/api/plants/:id', (req, res) => {
  const { id } = req.params;
  const plant = db.greenhouse.find(p => p.id === id) || db.salesfloor.find(p => p.id === id);
  if (!plant) return res.status(404).json({ error: 'Plant not found' });
  res.json(plant);
});




// NEW GAME mock endpoint called when the 'New Game' button is clicked on the Landing Page
app.post('/api/new-game', (req, res) => {
  nextId = 1;
  db = { balance: 200, greenhouse: [], salesfloor: []};
  res.status(201).json({ ok: true, state: db });
});


// EXIT GAME mock endpoint called when the 'Exit' button is clicked on the Landing Page
app.post('/api/exit-game', (req, res) => {
  db = { balance: 0, greenhouse: [], salesfloor: []};  // mock terminate/reset
  res.status(200).json({ ok: true });
});


// BUY PLANTS endpoint: body { flower:[n1,n2,n3], succulent:[n4,n5,n6], tree:[n7,n8,n9] }
app.post('/api/plants/buy', (req, res) => {
  try {
      const { flower = [0,0,0], succulent = [0,0,0], tree = [0,0,0] } = req.body || {};

      const groups = [
        { cat: 'flower', counts: flower, priceList: prices.flower },
        { cat: 'succulent', counts: succulent, priceList: prices.succulent },
        { cat: 'tree', counts: tree, priceList: prices.tree },
      ];

    
      let totalPlants = 0;
      let totalCost = 0;
      let plantsToAdd = []; // number of plants to add to the SoilGrid

      for (const g of groups) {
          g.counts.forEach((count, i) => {
            const c = Math.max(0, Math.floor(Number(count) || 0)); // ensure non-neg int
            totalPlants += c;
            totalCost += c * g.priceList[i];  // calculate totalCost to display on Menu
            for (let k = 0; k < c; k++) {
              plantsToAdd.push(createPlant(g.cat, i));
            }
          });
      }
      
      const available = CAPACITY - db.greenhouse.length;
      if (totalPlants === 0) {
        return res.status(400).json({ error: 'No plants selected' });
      }
      if (totalPlants > available) {
        return res.status(400).json({ error: `Exceeds capacity: available ${available}` });
      }
      if (totalCost > db.balance) {
        return res.status(400).json({ error: 'Insufficient balance', balance: db.balance });
      }

      db.balance -= totalCost;
      db.greenhouse.push(...plantsToAdd);   // adds plants to the greenhouse inventory

      res.json({
        ok: true,
        added: plantsToAdd.length,
        capacity: CAPACITY,
        used: db.greenhouse.length,
        balance: db.balance,
        greenhouse: db.greenhouse,
        totalCost,
      });
      console.log(`[${new Date().toISOString()}] Bought ${plantsToAdd.length} plant(s) for ${totalCost}. Balance=${db.balance}`);
  } catch (err) {
    console.error('BUY /api/plants/buy failed:', err);
    res.status(500).json({ error: 'Internal error' });
  }
});



// MOVE TO SALES FLOOR endpoint: 'moves' the mature plant from greenhouse inventory array to sales floor inventory array
app.post('/api/plants/:id/move-to-sales', (req, res) => {
  try {
    const { id } = req.params;
    const idx = db.greenhouse.findIndex(p => p.id === id);
    if (idx === -1) return res.status(404).json({ error: 'Plant not found in greenhouse' });

    const plant = db.greenhouse[idx];
    if (plant.maturity !== 'Sellable') {
      return res.status(400).json({ error: 'Plant is not sellable yet' });
    }

    db.greenhouse.splice(idx, 1); // removes specific plant from greenhouse
    db.salesfloor.push(plant);    // adds plant to sales floor 

    res.json({ ok: true, plant, used: db.greenhouse.length, salesfloor: db.salesfloor });

    // Prints in the terminal. Shows content of Greenhouse and Sales floor arrays as plants get moved to sales floor.
    console.log(`[${new Date().toISOString()}] Moved plant id=${plant.id} (${plant.category} ${plant.variety}) to salesfloor`);
    console.log('Greenhouse inventory:', db.greenhouse.map(p => ({ id: p.id, category: p.category, variety: p.variety })));
    console.log('Salesfloor inventory:', db.salesfloor.map(p => ({ id: p.id, category: p.category, variety: p.variety })));
  } catch (err) {
    console.error('POST /api/plants/:id/move-to-sales failed:', err);
    res.status(500).json({ error: 'Internal error' });
  }
});






app.get(/^\/(?!api).*/, (req, res) => {
  res.sendFile(path.resolve('frontend', 'public', 'index.html'));
});


app.listen(PORT, HOST, () => {
   console.log(`Listening on ${BASE_URL}`);
});
