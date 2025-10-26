#include "API.h"
#include "Game.h"

int main() {
    API myApi = API(new Game("../config.json"));
    myApi.bootstrap();
    return 0;
}