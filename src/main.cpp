#include "river.h"

#include "h/game.h"

int WinMain(){
    initGame();

    initGLFW();
    initVulkan();

    gameLoop();

    cleanupVulkan();
    cleanupGLFW();
}

//TODO: add other platforms
