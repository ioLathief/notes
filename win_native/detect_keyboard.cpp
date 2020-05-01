#include <windows.h>
#include <iostream>

//Example
HHOOK          kb_hook;

PKBDLLHOOKSTRUCT p;

DWORD virtualKey;

LRESULT CALLBACK kb_proc(int nCode, WPARAM wParam, LPARAM lParam) {

    if (nCode == HC_ACTION) {
        p = (PKBDLLHOOKSTRUCT)lParam;

        virtualKey = p->vkCode;

        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
        {
            std::cout<<"keyDown "<<std::endl;
            if(virtualKey==VK_LCONTROL){
                std::cout<<"keyDown LControl"<<std::endl;
            }
        }

        if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
        {
            std::cout<<"keyUp "<<std::endl;
        }
    }


    return CallNextHookEx(kb_hook, nCode, wParam, lParam);
}

void main() {
    kb_hook = SetWindowsHookEx(WH_KEYBOARD_LL, kb_proc, 0, 0);

    MSG msg{};
    while (GetMessage(&msg, 0, 0, 0) != 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(kb_hook);
}
