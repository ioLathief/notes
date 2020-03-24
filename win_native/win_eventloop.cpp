#include <iostream>
#include <windows.h>
#include <thread>


//manual message loop example
HHOOK mouseHook;
bool  close;

LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (close)
        PostQuitMessage(0);

    if (nCode == HC_ACTION) {
        if (wParam == WM_MBUTTONUP) {
            PostQuitMessage(0);
        }
    }

    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}

int main()
{

    //initializing
    close = false;
    mouseHook = SetWindowsHookEx(WH_MOUSE_LL, mouseProc, 0, 0);

    //manual message loop
    MSG msg{};
    while (!close && msg.message != WM_QUIT) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0) //Or use an if statement
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        Sleep(3);
    }
    UnhookWindowsHookEx(mouseHook);

    std::cout<<"Exit"<<std::endl;
    return 0;
}
