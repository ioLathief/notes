#pragma once


#include <functional>
#include <thread>
#include "Log.h"
#include "Core.h"


class eventHandler;
class evEmiter {
public:
    evEmiter();

    ~evEmiter();

    void doEvent();

    void process();

private:
    eventHandler *evHndl;
};

class eventHandler
{
    std::thread *evListenerThread;
    evEmiter *emiter;

public:
    explicit eventHandler(evEmiter *);

    ~eventHandler();

    void onEvent();
};

