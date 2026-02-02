#include "river.h"

#include "h/game.h"

int WinMain(){
    initGame();

    river::initGLFW();
    river::initVulkan();

    gameLoop();

    river::cleanupVulkan();
    river::cleanupGLFW();
}

//TODO: add other platforms
