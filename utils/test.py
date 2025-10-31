import asyncio
import websockets

async def connect_to_websocket(uri):
    async with websockets.connect(uri) as websocket:
        # Send a message
        await websocket.send("Hello WebSocket!")
        # Receive a message
        while True:
            response = await websocket.recv()
            print(f"Received: {response}")

if __name__ == "__main__":
    websocket_uri = "ws://localhost:8001"  # Example public echo server
    asyncio.run(connect_to_websocket(websocket_uri))
