#ifdef _WIN32 

#include "windows.h"

#include "river.h"
#include "window.h"

#include "game.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow)
{
    initGame();

    initGLFW();
    initVulkan();

    gameLoop();

    cleanupVulkan();
    cleanupGLFW();
}
#else

#include "river.h"
#include "window.h"

#include "game.h"

int main()
{
    initGame();

    initGLFW();
    initVulkan();

    gameLoop();

    cleanupVulkan();
    cleanupGLFW();
}
#endif
