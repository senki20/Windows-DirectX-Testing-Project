#include <iostream>
#include "WindowManager.h"

const wchar_t MainWindowClass[] = L"Main Window Class";
const wchar_t ProgressBarWindowClass[] = L"Progress Bar Window Class";


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the main window class
    Window mainWindow = CreateEmptyWindowClass(hInstance, L"Class Name", L"Main Window");
    mainWindow.ShowWindowClass();
    Window mainWindow2 = CreateEmptyWindowClass(hInstance, L"Class Name2", L"Main Window2");
    mainWindow2.ShowWindowClass();

    MainLoop();

    return 0;
}
