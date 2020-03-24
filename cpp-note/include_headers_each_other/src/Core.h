#pragma once

#include "Log.h"

#define logI(...) LOG_INFO((std::string)"" + __VA_ARGS__ )
#define logE(...) LOG_ERROR((std::string)"" + __VA_ARGS__ )
#define cing(x); std::cout << x << std::endl; std::cin.get()
#define cingA(x) cing("----Press Enter to "<< x )