#include "river.h"

#include "h/game.h"

int main(){

    initGLFW();
    initVulkan();

    initGame();
    gameLoop();

    cleanupVulkan();
    cleanupGLFW();
}
