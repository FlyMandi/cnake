#include "river.h"
#include "window.h"

#include "game.h"

#include <iostream>

void initGame(){
    using namespace river;

    appName = "cnake";
    appVersion = "0.0.1";

    //TODO: add error handling here
    window::WIDTH = 1920;
    window::HEIGHT = 1080;

    getProjectRoot(appName);

    std::ios_base::sync_with_stdio(false);
}

void gameLoop(){
    while(!window::SHOULDCLOSE){
        window::pollEvents();
        river::drawFrame();
    }
}
