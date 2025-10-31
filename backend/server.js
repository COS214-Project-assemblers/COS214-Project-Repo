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
    tree: ['Lemon', 'Apple', 'Oak', 'Maple', 'Pine', 'Banana'],
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

// Mock endpoint to get the nr of plants of the sales floor array 
app.get('/api/salesfloor', (req, res) => {
  res.json({
    salesfloor: db.salesfloor,
    count: Array.isArray(db.salesfloor) ? db.salesfloor.length : 0
  });
});

// Get details for a single plant by id
app.get('/api/plants/:id', (req, res) => {
  const { id } = req.params;
  const plant = db.greenhouse.find(p => p.id === id) || db.salesfloor.find(p => p.id === id);
  if (!plant) return res.status(404).json({ error: 'Plant not found' });
  res.json(plant);
});


// Mock endpoint: Get all the customers
app.get('/api/customers', (req, res) => {
  res.json({ customers });
});


// NEW GAME mock endpoint called when the 'New Game' button is clicked on the Landing Page
app.post('/api/new-game', (req, res) => {
  nextId = 1;
  customers = [];
  db = { balance: 500, greenhouse: [], salesfloor: []};
  res.status(201).json({ ok: true, state: db });
});


// EXIT GAME mock endpoint called when the 'Exit' button is clicked on the Landing Page
app.post('/api/exit-game', (req, res) => {
  db = { balance: 0, greenhouse: [], salesfloor: []};  // mock terminate/reset
  customers = [];
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



let customers = [];

// Mock function to create 3 customers, one each of type: 'ignorant', 'medium', 'greenfinger'
function makeCustomer(type) {
  const base = {
    ignorant: { 
      type: 'ignorant',
      name: 'Absent-minded Alice',
      introduction: "Heyyy... so... plants don't scream if I forget to water them, right?",
      preferences: "I need a plant that survives on good vibes and accidental neglect.",
      recommendations: "Which plant won't file a complaint if I forget it exists?",
      accept: "Nice! Even I can't mess this up. Probably.",
      acceptExit: "Thanks! If it dies, I'll just blame the sun!",
      reject: "That one sounds needy.",
      rejectExit: "Cool, I'll try another shop that believes in miracles.",
      offeredPlants: [
        { variety: 'Lemon', category: 'Tree', acceptable: 'yes', difficulty: 'hard' },
        { variety: 'Apple', category: 'Tree', acceptable: 'yes', difficulty: 'hard' },
        { variety: 'Daisy', category: 'Flower', acceptable: 'yes', difficulty: 'medium' },
        { variety: 'Cactus', category: 'Succulent', acceptable: 'yes', difficulty: 'easy' },
        { variety: 'Banana', category: 'Tree', acceptable: 'no', difficulty: 'hard' },
      ],
    },
    medium: {
      type: 'medium',
      name: 'Sensible Steve',
      introduction: "Hey there! My house is half jungle, half chaos — and I love it!",
      preferences: "I want a plant that forgives, but also flourishes.",
      recommendations: "Any plant that matches a vibe of mild responsibility?",
      accept: "Nice, that's exactly what I had in mind!",
      acceptExit: "Awesome, thanks! My plants are gonna gossip about this one.",
      reject: "Maybe something a bit more... forgiving?",
      rejectExit: "Thanks anyway! I'll browse a bit more.",
      offeredPlants: [
        { variety: 'Lemon', category: 'Tree', acceptable: 'no', difficulty: 'hard' },
        { variety: 'Banana', category: 'Tree', acceptable: 'no', difficulty: 'hard' },
        { variety: 'Aloe', category: 'Succulent', acceptable: 'yes', difficulty: 'easy' },
        { variety: 'Rose', category: 'Flower', acceptable: 'yes', difficulty: 'medium' },
        { variety: 'Jade', category: 'Succulent', acceptable: 'yes', difficulty: 'easy' },
      ],
    },
    greenfinger: {
      type: 'greenfinger',
      name: 'Greenfinger Greg',
      introduction: "Greetings! I'm hunting for something special for my collection.",
      preferences: "I prefer plants that reward careful attention.",
      recommendations: "What would you recommend that truly shines with care?",
      accept: "Excellent choice — that's perfect.",
      acceptExit: "Splendid! I'll add it to the conservatory.",
      reject: "Not quite what I had in mind.",
      rejectExit: "Thanks, but I'll pass for now.",
      offeredPlants: [
        { variety: 'Maple', category: 'Tree', acceptable: 'yes', difficulty: 'hard' },
        { variety: 'Pine', category: 'Tree', acceptable: 'yes', difficulty: 'hard' },
        { variety: 'Rose', category: 'Flower', acceptable: 'yes', difficulty: 'medium' },
        { variety: 'Tulip', category: 'Flower', acceptable: 'yes', difficulty: 'medium' },
        { variety: 'Daisy', category: 'Flower', acceptable: 'no', difficulty: 'easy' },
      ],
    }
  };
  return { id: String(Date.now() + Math.random()), type, ...base[type] };
}

// POST endpoint to initialise customers once to avoid an infinite loop :(
app.post('/api/customers/init', (req, res) => {
  customers = [];
  customers.push(makeCustomer('ignorant'));
  customers.push(makeCustomer('medium'));     
  customers.push(makeCustomer('greenfinger'));
  console.log(`[${new Date().toISOString()}] Customers initialised: total=${customers.length}`);
  res.status(201).json({ ok: true, total: customers.length });
});




// Mock endpoint to create customers when navigating to sales floor (called 3 times: ignorant, medium, greenfinger)
app.post('/api/customers/create', (req, res) => {
  const { type, count = 1 } = req.body || {};
  if (!['ignorant', 'medium', 'greenfinger'].includes(type)) {
    return res.status(400).json({ error: 'Invalid type' });
  }
  for (let i = 0; i < Number(count) || 1; i++) customers.push(makeCustomer(type));
  console.log(`[${new Date().toISOString()}] Created customer: type=${type}, count=${count}, total=${customers.length}`);
  res.status(201).json({ ok: true, total: customers.length });
});




// Sell a plant to the current customer selection: remove from salesfloor and add to balance
// Body: { category: 'Tree'|'Flower'|'Succulent', variety: 'Rose'|'Lemon'|... }
app.post('/api/sales/sell', (req, res) => {
  try {
    const { category, variety } = req.body || {};
    if (!category || !variety) return res.status(400).json({ error: 'category and variety required' });

    const catL = String(category).toLowerCase();
    const varL = String(variety).toLowerCase();

    const idx = db.salesfloor.findIndex(p =>
      String(p.category).toLowerCase() === catL &&
      String(p.variety).toLowerCase() === varL
    );
    if (idx === -1) return res.status(404).json({ error: 'Plant not found on salesfloor' });

    const [plant] = db.salesfloor.splice(idx, 1);  // remove from sales floor inventory
    const price = plant.sellPrice ?? (sellPrices[plant.kind]?.[plant.varietyIndex] ?? 0);
    db.balance += price;  // update player's balance

    console.log(`[${new Date().toISOString()}] Sold ${plant.category} ${plant.variety} for ${price}. Balance=${db.balance}`);
    console.log('Salesfloor inventory:', db.salesfloor.map(p => ({ id: p.id, category: p.category, variety: p.variety })));

    res.json({ ok: true, sellPrice: price, balance: db.balance, remaining: db.salesfloor.length });
  } catch (e) {
    console.error('POST /api/sales/sell failed:', e);
    res.status(500).json({ error: 'Internal error' });
  }
});

// Endpoint to reset customers
app.post('/api/customers/reset', (req, res) => {
  customers = [];
  res.json({ ok: true });
});









// don't modify this endpoint and leave it below all other endpoints
app.get(/^\/(?!api).*/, (req, res) => {
  res.sendFile(path.resolve('frontend', 'public', 'index.html'));
});


app.listen(PORT, HOST, () => {
   console.log(`Listening on ${BASE_URL}`);
});
