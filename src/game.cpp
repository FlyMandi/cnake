#include "river.h"

#include "h/game.h"

#include <iostream>

void initGame(){
    std::ios_base::sync_with_stdio(false);
    std::filesystem::path appRoot = getProjectRoot(appName);
    createMainMenu();
}

void gameLoop(){
    while(!window_SHOULDCLOSE){
        windowPollEvents();
        drawFrame();
    }
}

void createMainMenu(){

}
