#include "h/game.h"
//TODO: convert these into github submodules, then include back
#include "h/engine.h"
#include "h/window.h"

void initGame(){
    std::ios_base::sync_with_stdio(false);
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
