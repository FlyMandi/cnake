#include "river.h"
#include "window.h"

#include "game.h"

void initGame(){
    using namespace river;

    appName = "cnake";
    appVersion = "0.0.1";

    window::WIDTH = 1920;
    window::HEIGHT = 1080;

    getProjectRoot(appName);
}

void gameLoop(){
    while(!window::SHOULDCLOSE){
        window::pollEvents();
        river::drawFrame();
    }
}
