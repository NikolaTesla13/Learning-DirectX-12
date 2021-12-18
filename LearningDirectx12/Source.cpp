#include "System.h"
#include "Logger.h"
#include "Window.h"
#include "Timer.h"

using namespace Program;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    LoggerProps loggerProps;
    loggerProps.identificator = "Program";
    loggerProps.onlyDebug = true;
    loggerProps.shodID = true;
    loggerProps.showTime = true;

    Logger logger(loggerProps);
    logger.Output("Creating the window!");


    WindowProps windowProps;
    windowProps.height = 720;
    windowProps.width = 1080;
    windowProps.title = L"Learning DirectX 12";
    windowProps.instance = hInstance;

    Window window(windowProps);


    while (!window.ShouldClose())
    {
        window.BeginFrame();
        Timer timer("New frame");

        window.Quit();
        window.EndFrame();
    }

    return 0;
}