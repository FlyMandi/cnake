#include <river>

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
