"use strict";

var _express = _interopRequireDefault(require("express"));
var _path = _interopRequireDefault(require("path"));
var _cors = _interopRequireDefault(require("cors"));
var _xmlhttprequest = require("xmlhttprequest");
function _interopRequireDefault(e) { return e && e.__esModule ? e : { "default": e }; }
var app = (0, _express["default"])();
var HOST = 'localhost';
var PORT = 8000;
var BASE_URL = "http://".concat(HOST, ":").concat(PORT);
var _dirname = _path["default"].resolve();
app.use((0, _cors["default"])());
app.use(_express["default"].urlencoded({
  extended: false
}));
app.use(_express["default"].json());
app.use(_express["default"]["static"](_path["default"].join(_dirname, 'frontend', 'public')));

/* ================== MOCK API ENDPOINTS ==================== */

// example mock json object to initialise a game with a balance, 
// empty greenhouse inventory and empty salesfloor inventory
var db = {
  balance: 500,
  greenhouse: [],
  salesfloor: []
};
var nextId = 1;
var CAPACITY = 9; // capacity of greenhouse (SoilGrid)
var prices = {
  flower: [20, 25, 10],
  // mock cost prices for each variety displayed in the Menu
  succulent: [15, 20, 10],
  tree: [35, 20, 40]
};
var sellPrices = {
  // mock sell prices for each variety
  flower: [36, 45, 18],
  succulent: [27, 36, 18],
  tree: [63, 36, 72]
};

// Mock helper function to create a plant
function createPlant(category, varietyIndex) {
  var _varietyNames$categor, _varietyNames$categor2, _prices$category$vari, _prices$category, _sellPrices$category$, _sellPrices$category;
  var varietyNames = {
    flower: ['Rose', 'Tulip', 'Daisy'],
    succulent: ['Cactus', 'Aloe', 'Jade'],
    tree: ['Lemon', 'Apple', 'Oak']
  };
  var displayCategory = category.charAt(0).toUpperCase() + category.slice(1); // Flower/Succulent/Tree
  var varietyName = (_varietyNames$categor = (_varietyNames$categor2 = varietyNames[category]) === null || _varietyNames$categor2 === void 0 ? void 0 : _varietyNames$categor2[varietyIndex]) !== null && _varietyNames$categor !== void 0 ? _varietyNames$categor : "".concat(displayCategory, " ").concat(varietyIndex + 1);
  var costPrice = (_prices$category$vari = (_prices$category = prices[category]) === null || _prices$category === void 0 ? void 0 : _prices$category[varietyIndex]) !== null && _prices$category$vari !== void 0 ? _prices$category$vari : 0;
  var sellPrice = (_sellPrices$category$ = (_sellPrices$category = sellPrices[category]) === null || _sellPrices$category === void 0 ? void 0 : _sellPrices$category[varietyIndex]) !== null && _sellPrices$category$ !== void 0 ? _sellPrices$category$ : Math.round(costPrice * 1.8);
  return {
    id: String(nextId++),
    category: displayCategory,
    // string: "Flower" | "Succulent" | "Tree"
    variety: varietyName,
    // string: e.g. "Rose"
    healthScore: 100.0,
    // float
    pruningLevel: 0.0,
    // float
    waterLevel: 100.0,
    // float
    fertilizerLevel: 100.0,
    // float
    costPrice: costPrice,
    // int
    sellPrice: sellPrice,
    // int
    maturity: 'Not-Sellable',
    // boolean: "Sellable" | "Not-Sellable"
    kind: category,
    // 'flower' | 'succulent' | 'tree'
    varietyIndex: varietyIndex,
    stage: 'seedling'
  };
}

// Get current balance
app.get('/api/balance', function (req, res) {
  res.json({
    balance: db.balance
  });
});

// // Get the prices of the varieties
// app.get('/api/prices', (req, res) => {
//   res.json(prices);
// });

app.get('/api/cost-prices', function (req, res) {
  res.json(prices);
});
app.get('/api/sell-prices', function (req, res) {
  res.json(sellPrices);
});

// Mock endpoint to initialise the Greenhouse with a capacity of 9 plants and empty inventory
app.get('/api/greenhouse', function (req, res) {
  res.json({
    capacity: CAPACITY,
    used: db.greenhouse.length,
    greenhouse: db.greenhouse
  });
});

// Get details for a single plant by id
app.get('/api/plants/:id', function (req, res) {
  var id = req.params.id;
  var plant = db.greenhouse.find(function (p) {
    return p.id === id;
  }) || db.salesfloor.find(function (p) {
    return p.id === id;
  });
  if (!plant) return res.status(404).json({
    error: 'Plant not found'
  });
  res.json(plant);
});

// NEW GAME mock endpoint called when the 'New Game' button is clicked on the Landing Page
app.post('/api/new-game', function (req, res) {
  nextId = 1;
  db = {
    balance: 200,
    greenhouse: [],
    salesfloor: []
  };
  res.status(201).json({
    ok: true,
    state: db
  });
});

// EXIT GAME mock endpoint called when the 'Exit' button is clicked on the Landing Page
app.post('/api/exit-game', function (req, res) {
  db = {
    balance: 0,
    greenhouse: [],
    salesfloor: []
  }; // mock terminate/reset
  res.status(200).json({
    ok: true
  });
});

// BUY PLANTS endpoint: body { flower:[n1,n2,n3], succulent:[n4,n5,n6], tree:[n7,n8,n9] }
app.post('/api/plants/buy', function (req, res) {
  try {
    var _db$greenhouse;
    var _ref = req.body || {},
      _ref$flower = _ref.flower,
      flower = _ref$flower === void 0 ? [0, 0, 0] : _ref$flower,
      _ref$succulent = _ref.succulent,
      succulent = _ref$succulent === void 0 ? [0, 0, 0] : _ref$succulent,
      _ref$tree = _ref.tree,
      tree = _ref$tree === void 0 ? [0, 0, 0] : _ref$tree;
    var groups = [{
      cat: 'flower',
      counts: flower,
      priceList: prices.flower
    }, {
      cat: 'succulent',
      counts: succulent,
      priceList: prices.succulent
    }, {
      cat: 'tree',
      counts: tree,
      priceList: prices.tree
    }];
    var totalPlants = 0;
    var totalCost = 0;
    var plantsToAdd = []; // number of plants to add to the SoilGrid
    var _loop = function _loop() {
      var g = _groups[_i];
      g.counts.forEach(function (count, i) {
        var c = Math.max(0, Math.floor(Number(count) || 0)); // ensure non-neg int
        totalPlants += c;
        totalCost += c * g.priceList[i]; // calculate totalCost to display on Menu
        for (var k = 0; k < c; k++) {
          plantsToAdd.push(createPlant(g.cat, i));
        }
      });
    };
    for (var _i = 0, _groups = groups; _i < _groups.length; _i++) {
      _loop();
    }
    var available = CAPACITY - db.greenhouse.length;
    if (totalPlants === 0) {
      return res.status(400).json({
        error: 'No plants selected'
      });
    }
    if (totalPlants > available) {
      return res.status(400).json({
        error: "Exceeds capacity: available ".concat(available)
      });
    }
    if (totalCost > db.balance) {
      return res.status(400).json({
        error: 'Insufficient balance',
        balance: db.balance
      });
    }
    db.balance -= totalCost;
    (_db$greenhouse = db.greenhouse).push.apply(_db$greenhouse, plantsToAdd); // adds plants to the greenhouse inventory

    res.json({
      ok: true,
      added: plantsToAdd.length,
      capacity: CAPACITY,
      used: db.greenhouse.length,
      balance: db.balance,
      greenhouse: db.greenhouse,
      totalCost: totalCost
    });
    console.log("[".concat(new Date().toISOString(), "] Bought ").concat(plantsToAdd.length, " plant(s) for ").concat(totalCost, ". Balance=").concat(db.balance));
  } catch (err) {
    console.error('BUY /api/plants/buy failed:', err);
    res.status(500).json({
      error: 'Internal error'
    });
  }
});
app.get(/^\/(?!api).*/, function (req, res) {
  res.sendFile(_path["default"].resolve('frontend', 'public', 'index.html'));
});
app.listen(PORT, HOST, function () {
  console.log("Listening on ".concat(BASE_URL));
});