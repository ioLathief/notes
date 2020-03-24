#pragma once

#include "onEvCore.h"
#include <iostream>
#include "Core.h"
#include <windows.h>
#include <thread>

class Callable{
public:
    virtual void callbackFunc()
    {
    }
};

typedef void(Callable::*callbackFunction)();

class oneEv {
    std::string name;
    onEvCore* coreEv;
    Callable* callable;//do not delete
    callbackFunction cbFunc;
    std::thread *listenEvent{};
    std::thread *callbackThread{};

    bool isListen;

public:
    PROJETO_API explicit oneEv(const char *,Callable*);

    PROJETO_API void listenThread();

    PROJETO_API bool runFunc();


    PROJETO_API virtual ~oneEv();
private:
    void listenEvents();

};


