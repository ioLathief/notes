#include "evEmiter.h"

//std::function<void(evEmiter &)> *fun;
void evEmiter::process()
{
    logI("processing...");
    Sleep(5000);
    logI("processed!");
}

evEmiter::evEmiter()
{
    evHndl = new eventHandler(this);
    logI("evEmiter constructor");
}

evEmiter::~evEmiter()
{
    delete (evHndl);
    logI("evEmiter Destroctor!");
}

void evEmiter::doEvent()
{
    evHndl->onEvent();
}

