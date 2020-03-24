#pragma once

#include <windows.h>
#include <iostream>
#include "Core.h"

class evEmiter;
class eventHandler
{
    std::thread *evListenerThread;
    evEmiter *emiter;

public:
    explicit eventHandler(evEmiter *);

    ~eventHandler();

    void onEvent();
};


class evEmiter
{

public:
    evEmiter();

    ~evEmiter();

    void doEvent();

    void process();

private:
    eventHandler *evHndl;


};



