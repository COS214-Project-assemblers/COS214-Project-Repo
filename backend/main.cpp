#include "API.h"
#include "Game.h"
#include <cstdlib>
#include <string>

int main() {
    API myApi = API(new Game(getenv("GAME_CONFIG_PATH")));
    myApi.bootstrap();
    return 0;
}