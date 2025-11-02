/* Using the IndexedDB
 To add/update a record openDB().then(() => updateDBRecord(record));
 To read a record openDB().then(() => getPlantRecord(id)).then((returnVal) => { console.log(returnVal)} )

 Errors thrown and corrective actions taken:

 JSON SENT FROM SERVER COULD NOT BE PARSED
 1. Send message to server, {"error": failed to parse"} 
 2. Abort

 id NOT FOUND
 1. Send message to server {"error": "id not found"}
 2. Abort
 */

let db;

export function openDB() {
  return new Promise((resolve, reject) => {
    const request = indexedDB.open("plantDB", 1);

    request.onupgradeneeded = (event) => {
      const db = event.target.result;
      if (!db.objectStoreNames.contains("plants")) {
        const store = db.createObjectStore("plants", { keyPath: "id" });
        db.createObjectStore("plantCare", { keyPath: "id" });
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

export function updateDBRecord(record) {
  return new Promise((resolve, reject) => {
    const tx = db.transaction(["plants"], "readwrite");
    const store = tx.objectStore("plants");
    const getReq = store.get(record.id);

    getReq.onsuccess = () => {

      // console.log("Record id is" + record.id);
      const req = store.put(record);

      req.onerror = () => {
        reject("Failed to add");
      }

      req.onsuccess = () => { };

      resolve();
    }
  });
}

export function updateDBCare(id) {
  return new Promise((resolve, reject) => {
    const tx = db.transaction(["plantCare"], "readwrite");
    const store = tx.objectStore("plantCare");

    const req = store.put(id);

    req.onerror = () => {
      reject("Failed to add");
    }

    req.onsuccess = () => { };

    resolve();

  });
}

export function getPlantCare(id) {
  return new Promise((resolve, reject) => {
    const tx = db.transaction(["plantCare"], "readonly");
    const store = tx.objectStore("plantCare");
    const req = store.get(id);

    req.onsuccess = () => resolve(req.result ?? null);
    req.onerror = () => reject(req.error);
  });
}

export function getPlantRecord(id) {
  console.log("try get plant" + id);
  return new Promise((resolve, reject) => {
    const tx = db.transaction(["plants"], "readonly");
    const store = tx.objectStore("plants");
    const req = store.get(id);

    req.onsuccess = () => resolve(req.result ?? null);
    req.onerror = () => reject(req.error);
  });
}

export function getAllRecords() {
  return new Promise((resolve, reject) => {
    const tx = db.transaction(["plants"], "readonly");
    const store = tx.objectStore("plants");
    const request = store.getAll();

    request.onsuccess = () => {
      resolve(request.result);
    };

    request.onerror = (event) => {
      reject(event.target.error);
    };
  });
}

export function deletePlantRecord(id) {
  return new Promise((resolve, reject) => {
    const tx = db.transaction(["plants"], "readwrite");
    const store = tx.objectStore("plants");
    const req = store.delete(id);

    req.onsuccess = () => resolve(`Deleted plant ${id}`);
    req.onerror = () => reject(req.error);
  });
}

export function addPlantRecord(record) {
  return new Promise((resolve, reject) => {
    const tx = db.transaction(["plants"], 'readwrite');
    const store = tx.objectStore("plants");

    // Attempt to add
    const addReq = store.add(record);

    addReq.onsuccess = () => resolve('Record added successfully');

    addReq.onerror = (e) => {
      if (e.target.error.name === 'ConstraintError') {
        reject('Record already exists (duplicate key)');
      } else {
        reject('Failed to add record: ' + e.target.error);
      }
    }
  });
}
export function initSocket() {
  // const wsUri = "ws://localhost:8001"; FOR DEV SERVER 
  const wsUri = "ws://localhost:8080/ws"
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
    try {
      let jsonPlantData = JSON.parse(e.data);
      // console.log(jsonPlantData);
      if (jsonPlantData.id == undefined) {
        throw TypeError("id not found");
      }
      try {
        openDB().then(() => updateDBRecord(jsonPlantData));
        window.dispatchEvent(new CustomEvent('greenhouse:refresh'));
        window.dispatchEvent(new CustomEvent('salesfloor:refresh'));
        window.dispatchEvent(new CustomEvent('infocard:update'));
      } catch {
        throw Error("Failed to update/add record");
      }
    } catch (error) {
      if (error instanceof TypeError) {
        websocket.send(JSON.stringify({ "error": error.message }));
      } else {
        websocket.send(JSON.stringify({ "error": `Could not parse ${e.data} to json` }));
      }
    }
  });

  websocket.addEventListener("close", () => {
    console.log("DISCONNECTED");
  });
}

export function clearDB() {
  const request = indexedDB.deleteDatabase("plantDB");
  request.onsuccess = () => {
    console.log("Database deleted successfully");
  };
  request.onerror = (event) => {
    console.error("Failed to delete database:", event);
  };
  request.onblocked = () => {
    console.warn("Delete blocked (database still open in another tab)");
  };
}




