#if !defined(DEBUG) && defined(_WIN32)

#include "windows.h"

#include "river.h"
#include "window.h"

#include "game.h"

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, PWSTR cmdLine, int cmdShow)
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
