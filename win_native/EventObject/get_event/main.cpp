#include <stdio.h>
#include <iostream>
#include <windows.h>

HANDLE ghWriteEvent;
DWORD dwWaitResult;

int main()
{
    ghWriteEvent = CreateEvent(NULL, TRUE, FALSE, TEXT("WriteEvdent"));
    dwWaitResult = WaitForSingleObject(ghWriteEvent, INFINITE);
    if(dwWaitResult==WAIT_OBJECT_0)
        std::cout<<"something is occured"<<std::endl;
    return 0;
}