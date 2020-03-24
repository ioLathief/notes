#include "onEvCore.h"

onEvCore::onEvCore(const char *name)
{
    this->name = name;
    createEvent();
}

onEvCore::~onEvCore()
{
    CloseHandle(hEvent);
}

bool onEvCore::setEvent()
{
    return SetEvent(hEvent) != 0;
}

bool onEvCore::unsetEvent()
{
    return ResetEvent(hEvent) != 0;
}

bool onEvCore::createEvent()
{
    hEvent = CreateEvent(NULL, TRUE, FALSE, this->name.c_str());
    return hEvent != nullptr;
}

bool onEvCore::isSigned()
{
    return WaitForSingleObject(hEvent, 10) == WAIT_OBJECT_0;
}

bool onEvCore::listen()
{
    return WaitForSingleObject(hEvent, INFINITE) == WAIT_OBJECT_0;
}
