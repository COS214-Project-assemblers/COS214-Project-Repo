#include "API.h"
#include "game/SetEnv.h"

int main() {
    SetEnv setGameEnv;
    API myApi = API(nullptr);
    myApi.bootstrap();
    return 0;
}