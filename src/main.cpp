#include "river.h"
#include "window.h"

#include "game.h"

int WinMain(){
    initGame();

    initGLFW();
    initVulkan();

    gameLoop();

    cleanupVulkan();
    cleanupGLFW();
}

int main(){
    initGame();

    initGLFW();
    initVulkan();

    gameLoop();

    cleanupVulkan();
    cleanupGLFW();
}
