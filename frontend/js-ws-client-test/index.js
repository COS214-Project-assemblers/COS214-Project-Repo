function initDB() {
    const request = indexedDB.open("plantDB", 1);

    request.onupgradeneeded = (event) => {
        const db = event.target.result;
        db.createObjectStore("plants", { keyPath: "plantId" });
    };
}

function addDBRecord(record) {
    const request = indexedDB.open("plantDB", 1);
    request.onsuccess = (event) => {
      const db = event.target.result;
      const tx = db.transaction("plants", "readwrite");
      const store = tx.objectStore("plants");

      store.put(record);

      tx.oncomplete = () => db.close();
    };
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
        console.log(`RECEIVED: ${e.data}`);
        try {
            JSON.parse(e.data);
        } catch (error) {
            websocket.send(JSON.stringify({"error": `Could not parse ${e.data} to json`}));
        }
    });

    websocket.addEventListener("close", () => {
      console.log("DISCONNECTED");
    });
}

function initShit() {
    document.getElementById("regular-shit").addEventListener("click", () => {
        randoItem = document.createElement("li");
        randoItem.textContent = "hihi";
        document.getElementById("rando-list").appendChild(randoItem); 
    });
}

initShit();
initSocket();