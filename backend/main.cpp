#include "API.h"
#include "Game.h"
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    
    char* gameConfigPath = getenv("GAME_CONFIG_PATH");
    if (gameConfigPath == nullptr) {
        cout << "GAME_CONFIG_PATH environment variable not set, exiting..." << endl;
        exit(EXIT_FAILURE);
    }
    API myApi = API(new Game(gameConfigPath));
    myApi.bootstrap();
    return 0;
}