/* Using the IndexedDB
 To add/update a record openDB().then(() => addDBRecord(record));
 To read a record openDB().then(() => getPlantRecord(plantID)).then((returnVal) => { console.log(returnVal)} )

 Errors thrown and corrective actions taken:

 JSON SENT FROM SERVER COULD NOT BE PARSED
 1. Send message to server, {"error": failed to parse"} 
 2. Abort

 PLANTID NOT FOUND
 1. Send message to server {"error": "plantId not found"}
 2. Abort
 */

let db;

function openDB() {
  return new Promise((resolve, reject) => {
    const request = indexedDB.open("plantDB", 1);

    request.onupgradeneeded = (event) => {
      const db = event.target.result;
      if (!db.objectStoreNames.contains("plants")) {
        const store = db.createObjectStore("plants", { keyPath: "plantId" });
        store.createIndex("byCategory", "plantCategory", { unique: false });
        store.createIndex("byVariety", "plantVariety", { unique: false });
      }
    };

    request.onsuccess = (event) => {
      db = event.target.result;
      resolve(db);
    };

    request.onerror = () => reject(request.error);
  });
}

function addDBRecord(record) {
  return new Promise((resolve, reject) => {
    const tx = db.transaction(["plants"], "readwrite");
    const store = tx.objectStore("plants");
    const req = store.put(record); 

    req.onerror = () => reject(req.error);
    tx.oncomplete = () => resolve(); 
    tx.onerror = () => reject(tx.error);
  });
}


function getPlantRecord(plantId) {
  return new Promise((resolve, reject) => {
    const tx = db.transaction(["plants"], "readonly");
    const store = tx.objectStore("plants");
    const req = store.get(plantId);

    req.onsuccess = () => resolve(req.result ?? null);
    req.onerror = () => reject(req.error);
  });
}


function initSocket() {
    const wsUri = "ws://localhost:8001"
    const websocket = new WebSocket(wsUri);

    websocket.addEventListener("open", () => {
        console.log("CONNECTED");
    });

    websocket.addEventListener("error", (e) => {
        console.log(`ERROR`);
    });

    websocket.addEventListener("message", (e) => {
        // Here the message will be parsed and then stored in IndexedDB and if applicable update
        // plant elements
        console.log(`RECEIVED: ${e.data}`);
        try {
            let jsonPlantData = JSON.parse(e.data);
            if (jsonPlantData.plantId == undefined) {
              throw TypeError("PlantID not found");
            }
        } catch (error) {
            if (error instanceof TypeError) {
              
            } else {
              websocket.send(JSON.stringify({"error": `Could not parse ${e.data} to json`}));
            }
        }
    });

    websocket.addEventListener("close", () => {
      console.log("DISCONNECTED");
    });
}

openDB()
  .then(() => addDBRecord({ 
      plantId: "3f6a2d2b-7a5e-4f06-9b4f-2f8e6a2c9b8d",
      plantCategory: "succulent",
      plantVariety: "cactus",
      healthScore: 0.5,
      waterScore: 10,
      pruningScore: 10,
      fertilizerScore: 10,
      sellable: false,
      died: false
    }))
  .then(() => getPlantRecord(1))
  .then((rec) => {
    if (rec) {
      console.log("Plant found:", rec);
    } else {
      console.log("Plant not found");
    }
  })
  .catch((err) => console.error("DB error:", err));

