#include "API.h"
#include "Game.h"
#include <cstdlib>
#include <string>
#include <thread>
#include "GreenSock.h"

using namespace std;

void startGameApi() {
    char* gameConfigPath = getenv("GAME_CONFIG_PATH");
    if (gameConfigPath == nullptr) {
        cout << "GAME_CONFIG_PATH environment variable not set, exiting..." << endl;
        exit(EXIT_FAILURE);
    }
    API myApi = API(new Game(gameConfigPath));
    myApi.bootstrap();
}

void startGreenSock() {
    GreenSock ws = GreenSock();
    ws.bootstrap();
}

int main() {
    std::thread gameApi(startGameApi);
    std::thread greenSock(startGreenSock);

    gameApi.join();
    greenSock.join();
    return 0;
}