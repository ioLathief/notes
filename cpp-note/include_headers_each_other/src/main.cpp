#include <iostream>
#include "evEmiter.h"
#include "Core.h"

int main()
{
    {
        Log::Init();

        cingA("create emiter");
        evEmiter emiter;

        cingA("run doEvent function");
        emiter.doEvent();

        cingA("ExitScope");
    }
    return 0;
}
