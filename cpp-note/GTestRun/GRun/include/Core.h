#pragma once

#ifdef PLATFORM_WINDOWS
    #ifdef PROJETO_BUILD_DLL
        #define PROJETO_API __declspec(dllexport)
    #else
        #ifdef PROJETO_DLL
            #define PROJETO_API __declspec(dllimport)
        #else 
            #define PROJETO_API
        #endif
    #endif
#else
    #error Hazel Only Support Windows!
#endif
