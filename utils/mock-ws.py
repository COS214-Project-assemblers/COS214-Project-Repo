# Minimal echo WebSocket server with Python 'websockets'
# Works with websockets>=10
import asyncio
import websockets
import time

HOST = "0.0.0.0"
PORT = 8001

TEST_STRINGS = ['{"plantId": "f296643c-f3bc-4d3a-8eb8-0b3b462a0d67", "plantCategory": "succulent", "plantVariety": "cactus", "healthScore": 0.5, "waterScore": 10, "pruningScore": 10, "fertilizerScore": 10, "sellable": false, "died": false}'
                , '{"plantId": "0163b116-a4a8-4dfb-b21e-755b4ac4481e", "plantCategory": "flower", "plantVariety": "daisy", "healthScore": 0.9, "waterScore": 10, "pruningScore": 10, "fertilizerScore": 10, "sellable": false, "died": false}']


async def echo_handler(ws: websockets.WebSocketServerProtocol):
    
    async def receiver():
        async for msg in ws:
            print(msg)

    async def periodic_sender():
        test_size = len(TEST_STRINGS)
        i = 0
        while True:
            await asyncio.sleep(2)
            await ws.send(TEST_STRINGS[i])
            i = (i + 1) % test_size

    # Run both coroutines concurrently
    try:
        await asyncio.gather(receiver(), periodic_sender())
    except websockets.ConnectionClosedOK:
        pass
    except websockets.ConnectionClosedError as e:
        print(f"Connection closed with error: {e}")
    finally:
        print("Client disconnected")

async def main():
    async with websockets.serve(
        echo_handler,
        HOST,
        PORT,
        ping_interval=20,      # keepalive pings
        ping_timeout=20,
    ):
        print(f"WebSocket server listening on ws://{HOST}:{PORT}")
        await asyncio.Future()  # run forever

if __name__ == "__main__":
    asyncio.run(main())
