#include "river.h"

#include "h/game.h"

int WinMain(){

    initGLFW();
    initVulkan();

    initGame();
    gameLoop();

    cleanupVulkan();
    cleanupGLFW();
}

//TODO: add other platforms
