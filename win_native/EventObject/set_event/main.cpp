#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
HANDLE ghWriteEvent;
#define Seconds 5


int main()
{
   ghWriteEvent = CreateEvent(NULL, TRUE, FALSE, TEXT("WriteEvdent"));

    for(int i=0;i<Seconds;++i)
    {
        Sleep(1000);
        std::cout << "  - "<<(i+1)<<" second "<<std::endl;
    }
    SetEvent(ghWriteEvent);
    return 0;
}