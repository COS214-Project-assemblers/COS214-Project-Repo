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
  balance: 200,
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

// Mock helper function to create a plant
function createPlant(category, varietyIndex) {
  return {
    id: String(nextId++),
    category,              // 'flower' | 'succulent' | 'tree'
    variety: varietyIndex, // 0, 1 or 2 
    stage: 'seedling'      // or whatever the initial state is, notMature?
  };
}

// Get current balance
app.get('/api/balance', (req, res) => {
  res.json({ balance: db.balance });
});

// Get the prices of the varieties
app.get('/api/prices', (req, res) => {
  res.json(prices);
});

// Mock endpoint to initialise the Greenhouse with a capacity of 9 plants and empty inventory
app.get('/api/greenhouse', (req, res) => {
  res.json({
    capacity: CAPACITY,
    used: db.greenhouse.length,
    greenhouse: db.greenhouse,
  });
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





app.get(/^\/(?!api).*/, (req, res) => {
  res.sendFile(path.resolve('frontend', 'public', 'index.html'));
});


app.listen(PORT, HOST, () => {
   console.log(`Listening on ${BASE_URL}`);
});
