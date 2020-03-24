#include <windows.h>
#include <iostream>

HHOOK          mouse_hook;
MSLLHOOKSTRUCT *mStruct;

LRESULT CALLBACK mouse_proc(int nCode, WPARAM wParam, LPARAM lParam) {

    if (nCode == HC_ACTION) {

        if (wParam == WM_MOUSEWHEEL) {
            mStruct = (MSLLHOOKSTRUCT *) lParam;
            std::cout << "scroll " ;
            if((static_cast<int>(mStruct->mouseData) >> 16) > 0 ){
                std::cout<<"up"<<std::endl;
            } else
                std::cout<<"down"<<std::endl;
        }

        if (wParam == WM_MOUSEMOVE) {
            mStruct = (MSLLHOOKSTRUCT *) lParam;
            std::cout << "move : x: " << (static_cast<int>(mStruct->pt.x)) << " y: "
                      << (static_cast<int>(mStruct->pt.y)) << std::endl;
            if (static_cast<int>(mStruct->pt.x) == -1 && static_cast<int>(mStruct->pt.y) == -1)
                PostQuitMessage(0);
        }

        if (wParam == WM_LBUTTONDOWN) {
            std::cout << "Left Button Down" << std::endl;
        }

        if (wParam == WM_LBUTTONUP) {
            std::cout << "Left Button Up" << std::endl;
        }

        if (wParam == WM_RBUTTONDOWN) {
            std::cout << "Right Button Down" << std::endl;
        }

        if (wParam == WM_RBUTTONUP) {
            std::cout << "Right Button Up" << std::endl;
        }

        if (wParam == WM_MBUTTONDOWN) {
            std::cout << "Middle Button Down" << std::endl;
        }

        if (wParam == WM_MBUTTONUP) {
            std::cout << "Middle Button Up" << std::endl;
        }
    }


    return CallNextHookEx(mouse_hook, nCode, wParam, lParam);
}

int main() {
    mouse_hook = SetWindowsHookEx(WH_MOUSE_LL, mouse_proc, 0, 0);

    MSG msg{};
    while (GetMessage(&msg, 0, 0, 0) != 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(mouse_hook);
}
