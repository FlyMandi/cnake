#include "river.h"
#include "window.h"

#include "game.h"

int WinMain(){
    initGame();

    window::initGLFW();
    river::initVulkan();

    gameLoop();

    river::cleanupVulkan();
    window::cleanupGLFW();
}

//TODO: add other platforms
