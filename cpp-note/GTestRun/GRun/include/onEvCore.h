#pragma once

#include <windows.h>
#include "Core.h"
#include "iostream"

class onEvCore {
    std::string name;
    HANDLE hEvent{};

    bool createEvent();

public:
    PROJETO_API explicit onEvCore(const char *name);

    onEvCore(const onEvCore &) = delete;

    PROJETO_API ~onEvCore();

    PROJETO_API bool setEvent();

    PROJETO_API bool unsetEvent();


    PROJETO_API bool isSigned();

    PROJETO_API bool listen();

};


