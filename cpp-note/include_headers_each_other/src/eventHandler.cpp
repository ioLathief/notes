#include "eventHandler.h"


eventHandler::eventHandler( evEmiter *games)
{
    logI("eventHandler constructor");
    emiter = games;
}

eventHandler::~eventHandler()
{
    logI("eventHandler destructor");
    if (evListenerThread != nullptr)
    {
        if (evListenerThread->joinable())
            evListenerThread->join();

        delete (evListenerThread);
    } else
        logE("evlistener thread null");
}

void eventHandler::onEvent()
{
    evListenerThread = new std::thread(&evEmiter::process,emiter);
    logI("thread created!");
}

