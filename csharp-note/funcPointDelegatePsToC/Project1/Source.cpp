#include <iostream>
#define EXTERN_C extern "C"

void (*Func1)(void);

EXTERN_C __declspec(dllexport) void __stdcall TestDelegate(void (*func)(void),const char * _strs)
{
    std::cout << "_satrs : " << _strs << std::endl;
    func();
}