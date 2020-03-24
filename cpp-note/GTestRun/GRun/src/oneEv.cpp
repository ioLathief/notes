#include "oneEv.h"

PROJETO_API void oneEv::listenThread()
{
    listenEvent = new std::thread(&oneEv::listenEvents,this);
}

oneEv::oneEv(const char *name, Callable* callable)
{
    this->name = name;
    this->callable = callable;
    this->cbFunc = &Callable::callbackFunc;
    this->coreEv = new onEvCore(this->name.c_str());
}

bool oneEv::runFunc()
{
    return coreEv->setEvent();
}

oneEv::~oneEv()
{
    delete coreEv;

    if(listenEvent->joinable())
        listenEvent->join();

    if(callbackThread->joinable())
        callbackThread->join();

    delete listenEvent;
    delete callbackThread;
}

void oneEv::listenEvents()
{
    coreEv->listen();
    callbackThread = new std::thread(cbFunc,callable);
}

