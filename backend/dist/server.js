"use strict";

var _express = _interopRequireDefault(require("express"));
var _path = _interopRequireDefault(require("path"));
var _cors = _interopRequireDefault(require("cors"));
var _xmlhttprequest = require("xmlhttprequest");
function _interopRequireDefault(e) { return e && e.__esModule ? e : { "default": e }; }
function _typeof(o) { "@babel/helpers - typeof"; return _typeof = "function" == typeof Symbol && "symbol" == typeof Symbol.iterator ? function (o) { return typeof o; } : function (o) { return o && "function" == typeof Symbol && o.constructor === Symbol && o !== Symbol.prototype ? "symbol" : typeof o; }, _typeof(o); }
function _slicedToArray(r, e) { return _arrayWithHoles(r) || _iterableToArrayLimit(r, e) || _unsupportedIterableToArray(r, e) || _nonIterableRest(); }
function _nonIterableRest() { throw new TypeError("Invalid attempt to destructure non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); }
function _unsupportedIterableToArray(r, a) { if (r) { if ("string" == typeof r) return _arrayLikeToArray(r, a); var t = {}.toString.call(r).slice(8, -1); return "Object" === t && r.constructor && (t = r.constructor.name), "Map" === t || "Set" === t ? Array.from(r) : "Arguments" === t || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(t) ? _arrayLikeToArray(r, a) : void 0; } }
function _arrayLikeToArray(r, a) { (null == a || a > r.length) && (a = r.length); for (var e = 0, n = Array(a); e < a; e++) n[e] = r[e]; return n; }
function _iterableToArrayLimit(r, l) { var t = null == r ? null : "undefined" != typeof Symbol && r[Symbol.iterator] || r["@@iterator"]; if (null != t) { var e, n, i, u, a = [], f = !0, o = !1; try { if (i = (t = t.call(r)).next, 0 === l) { if (Object(t) !== t) return; f = !1; } else for (; !(f = (e = i.call(t)).done) && (a.push(e.value), a.length !== l); f = !0); } catch (r) { o = !0, n = r; } finally { try { if (!f && null != t["return"] && (u = t["return"](), Object(u) !== u)) return; } finally { if (o) throw n; } } return a; } }
function _arrayWithHoles(r) { if (Array.isArray(r)) return r; }
function ownKeys(e, r) { var t = Object.keys(e); if (Object.getOwnPropertySymbols) { var o = Object.getOwnPropertySymbols(e); r && (o = o.filter(function (r) { return Object.getOwnPropertyDescriptor(e, r).enumerable; })), t.push.apply(t, o); } return t; }
function _objectSpread(e) { for (var r = 1; r < arguments.length; r++) { var t = null != arguments[r] ? arguments[r] : {}; r % 2 ? ownKeys(Object(t), !0).forEach(function (r) { _defineProperty(e, r, t[r]); }) : Object.getOwnPropertyDescriptors ? Object.defineProperties(e, Object.getOwnPropertyDescriptors(t)) : ownKeys(Object(t)).forEach(function (r) { Object.defineProperty(e, r, Object.getOwnPropertyDescriptor(t, r)); }); } return e; }
function _defineProperty(e, r, t) { return (r = _toPropertyKey(r)) in e ? Object.defineProperty(e, r, { value: t, enumerable: !0, configurable: !0, writable: !0 }) : e[r] = t, e; }
function _toPropertyKey(t) { var i = _toPrimitive(t, "string"); return "symbol" == _typeof(i) ? i : i + ""; }
function _toPrimitive(t, r) { if ("object" != _typeof(t) || !t) return t; var e = t[Symbol.toPrimitive]; if (void 0 !== e) { var i = e.call(t, r || "default"); if ("object" != _typeof(i)) return i; throw new TypeError("@@toPrimitive must return a primitive value."); } return ("string" === r ? String : Number)(t); }
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
    healthScore: 100,
    // percentage, 0% == dead plant, 20% - 50% == orange plant, less than 20% == red plant
    pruningLevel: 0,
    // out of 3?
    waterLevel: 100,
    fertilizerLevel: 100,
    costPrice: costPrice,
    // int
    sellPrice: sellPrice,
    // int
    maturity: 'Not-Sellable',
    // boolean: "Sellable" | "Not-Sellable", a Sellable plant has a star added (visual indicator)
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

// Mock endpoint to get the nr of plants of the sales floor array 
app.get('/api/salesfloor', function (req, res) {
  res.json({
    salesfloor: db.salesfloor,
    count: Array.isArray(db.salesfloor) ? db.salesfloor.length : 0
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

// Mock endpoint: Get all the customers
app.get('/api/customers', function (req, res) {
  res.json({
    customers: customers
  });
});

// NEW GAME mock endpoint called when the 'New Game' button is clicked on the Landing Page
app.post('/api/new-game', function (req, res) {
  nextId = 1;
  customers = [];
  db = {
    balance: 500,
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
  customers = [];
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

// MOVE TO SALES FLOOR endpoint: 'moves' the mature plant from greenhouse inventory array to sales floor inventory array
app.post('/api/plants/:id/move-to-sales', function (req, res) {
  try {
    var id = req.params.id;
    var idx = db.greenhouse.findIndex(function (p) {
      return p.id === id;
    });
    if (idx === -1) return res.status(404).json({
      error: 'Plant not found in greenhouse'
    });
    var plant = db.greenhouse[idx];
    if (plant.maturity !== 'Sellable') {
      return res.status(400).json({
        error: 'Plant is not sellable yet'
      });
    }
    db.greenhouse.splice(idx, 1); // removes specific plant from greenhouse
    db.salesfloor.push(plant); // adds plant to sales floor 

    res.json({
      ok: true,
      plant: plant,
      used: db.greenhouse.length,
      salesfloor: db.salesfloor
    });

    // Prints in the terminal. Shows content of Greenhouse and Sales floor arrays as plants get moved to sales floor.
    console.log("[".concat(new Date().toISOString(), "] Moved plant id=").concat(plant.id, " (").concat(plant.category, " ").concat(plant.variety, ") to salesfloor"));
    console.log('Greenhouse inventory:', db.greenhouse.map(function (p) {
      return {
        id: p.id,
        category: p.category,
        variety: p.variety
      };
    }));
    console.log('Salesfloor inventory:', db.salesfloor.map(function (p) {
      return {
        id: p.id,
        category: p.category,
        variety: p.variety
      };
    }));
  } catch (err) {
    console.error('POST /api/plants/:id/move-to-sales failed:', err);
    res.status(500).json({
      error: 'Internal error'
    });
  }
});
var customers = [];

// Mock function to create 3 customers, one each of type: 'ignorant', 'medium', 'greenfinger'
function makeCustomer(type) {
  var base = {
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
      offeredPlants: [{
        variety: 'Lemon',
        category: 'Tree',
        acceptable: 'yes',
        difficulty: 'hard'
      }, {
        variety: 'Apple',
        category: 'Tree',
        acceptable: 'yes',
        difficulty: 'hard'
      }, {
        variety: 'Daisy',
        category: 'Flower',
        acceptable: 'yes',
        difficulty: 'medium'
      }, {
        variety: 'Cactus',
        category: 'Succulent',
        acceptable: 'yes',
        difficulty: 'easy'
      }, {
        variety: 'Banana',
        category: 'Tree',
        acceptable: 'no',
        difficulty: 'hard'
      }]
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
      offeredPlants: [{
        variety: 'Lemon',
        category: 'Tree',
        acceptable: 'no',
        difficulty: 'hard'
      }, {
        variety: 'Banana',
        category: 'Tree',
        acceptable: 'no',
        difficulty: 'hard'
      }, {
        variety: 'Aloe',
        category: 'Succulent',
        acceptable: 'yes',
        difficulty: 'easy'
      }, {
        variety: 'Rose',
        category: 'Flower',
        acceptable: 'yes',
        difficulty: 'medium'
      }, {
        variety: 'Jade',
        category: 'Succulent',
        acceptable: 'yes',
        difficulty: 'easy'
      }]
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
      offeredPlants: [{
        variety: 'Maple',
        category: 'Tree',
        acceptable: 'yes',
        difficulty: 'hard'
      }, {
        variety: 'Pine',
        category: 'Tree',
        acceptable: 'yes',
        difficulty: 'hard'
      }, {
        variety: 'Rose',
        category: 'Flower',
        acceptable: 'yes',
        difficulty: 'medium'
      }, {
        variety: 'Tulip',
        category: 'Flower',
        acceptable: 'yes',
        difficulty: 'medium'
      }, {
        variety: 'Daisy',
        category: 'Flower',
        acceptable: 'no',
        difficulty: 'easy'
      }]
    }
  };
  return _objectSpread({
    id: String(Date.now() + Math.random()),
    type: type
  }, base[type]);
}

// POST endpoint to initialise customers once to avoid an infinite loop :(
app.post('/api/customers/init', function (req, res) {
  customers = [];
  customers.push(makeCustomer('ignorant'));
  customers.push(makeCustomer('medium'));
  customers.push(makeCustomer('greenfinger'));
  console.log("[".concat(new Date().toISOString(), "] Customers initialised: total=").concat(customers.length));
  res.status(201).json({
    ok: true,
    total: customers.length
  });
});

// Mock endpoint to create customers when navigating to sales floor (called 3 times: ignorant, medium, greenfinger)
app.post('/api/customers/create', function (req, res) {
  var _ref2 = req.body || {},
    type = _ref2.type,
    _ref2$count = _ref2.count,
    count = _ref2$count === void 0 ? 1 : _ref2$count;
  if (!['ignorant', 'medium', 'greenfinger'].includes(type)) {
    return res.status(400).json({
      error: 'Invalid type'
    });
  }
  for (var i = 0; i < Number(count) || 1; i++) customers.push(makeCustomer(type));
  console.log("[".concat(new Date().toISOString(), "] Created customer: type=").concat(type, ", count=").concat(count, ", total=").concat(customers.length));
  res.status(201).json({
    ok: true,
    total: customers.length
  });
});

// Sell a plant to the current customer selection: remove from salesfloor and add to balance
// Body: { category: 'Tree'|'Flower'|'Succulent', variety: 'Rose'|'Lemon'|... }
app.post('/api/sales/sell', function (req, res) {
  try {
    var _plant$sellPrice, _sellPrices$plant$kin, _sellPrices$plant$kin2;
    var _ref3 = req.body || {},
      category = _ref3.category,
      variety = _ref3.variety;
    if (!category || !variety) return res.status(400).json({
      error: 'category and variety required'
    });
    var catL = String(category).toLowerCase();
    var varL = String(variety).toLowerCase();
    var idx = db.salesfloor.findIndex(function (p) {
      return String(p.category).toLowerCase() === catL && String(p.variety).toLowerCase() === varL;
    });
    if (idx === -1) return res.status(404).json({
      error: 'Plant not found on salesfloor'
    });
    var _db$salesfloor$splice = db.salesfloor.splice(idx, 1),
      _db$salesfloor$splice2 = _slicedToArray(_db$salesfloor$splice, 1),
      plant = _db$salesfloor$splice2[0]; // remove from sales floor inventory
    var price = (_plant$sellPrice = plant.sellPrice) !== null && _plant$sellPrice !== void 0 ? _plant$sellPrice : (_sellPrices$plant$kin = (_sellPrices$plant$kin2 = sellPrices[plant.kind]) === null || _sellPrices$plant$kin2 === void 0 ? void 0 : _sellPrices$plant$kin2[plant.varietyIndex]) !== null && _sellPrices$plant$kin !== void 0 ? _sellPrices$plant$kin : 0;
    db.balance += price; // update player's balance

    console.log("[".concat(new Date().toISOString(), "] Sold ").concat(plant.category, " ").concat(plant.variety, " for ").concat(price, ". Balance=").concat(db.balance));
    console.log('Salesfloor inventory:', db.salesfloor.map(function (p) {
      return {
        id: p.id,
        category: p.category,
        variety: p.variety
      };
    }));
    res.json({
      ok: true,
      sellPrice: price,
      balance: db.balance,
      remaining: db.salesfloor.length
    });
  } catch (e) {
    console.error('POST /api/sales/sell failed:', e);
    res.status(500).json({
      error: 'Internal error'
    });
  }
});

// Endpoint to reset customers
app.post('/api/customers/reset', function (req, res) {
  customers = [];
  res.json({
    ok: true
  });
});

// don't modify this endpoint and leave it below all other endpoints
app.get(/^\/(?!api).*/, function (req, res) {
  res.sendFile(_path["default"].resolve('frontend', 'public', 'index.html'));
});
app.listen(PORT, HOST, function () {
  console.log("Listening on ".concat(BASE_URL));
});