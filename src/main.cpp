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

int main(){
    initGame();

    window::initGLFW();
    river::initVulkan();

    gameLoop();

    river::cleanupVulkan();
    window::cleanupGLFW();
}
