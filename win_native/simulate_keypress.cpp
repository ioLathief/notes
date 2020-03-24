#include <windows.h>
#include <iostream>


/*
 * VK codes https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes
 * */

void simulatePress(BYTE vkCode)
{
        // Simulate a key down
        keybd_event( vkCode,
                     0x45,
                     KEYEVENTF_EXTENDEDKEY | 0,
                     0 );

        // Simulate a key up
        keybd_event( vkCode,
                     0x45,
                     KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                     0);

}


int main()
{
    Sleep(5000);
    simulatePress(0x41); // A
    std::cin.get();
    return 0;
}