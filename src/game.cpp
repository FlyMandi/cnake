#include "river.h"
#include "window.h"

#include "game.h"

void initGame()
{
    appName = "cnake";
    appVersion = "0.0.1";

    WIDTH = 1920;
    HEIGHT = 1080;

    appRoot = getProjectRoot(appName);
}

void gameLoop(){
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        drawFrame();
    }
}
