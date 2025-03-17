#include "river.h"

#include "h/game.h"

#include <iostream>

void initGame(){
    appName = "cnake";
    appVersion = "0.0.1";

    appRoot = getProjectRoot(appName);
    debugLog = appRoot / "debug.log";

    std::ios_base::sync_with_stdio(false);
}

void gameLoop(){
    while(!window_SHOULDCLOSE){
        windowPollEvents();
        drawFrame();
    }
}
