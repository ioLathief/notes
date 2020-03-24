#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::logger> Log::s_CoreLogger;

void Log::Init()
{
    spdlog::set_pattern("[%t] %n: %^%v%$");
    s_CoreLogger = spdlog::stdout_color_mt("testCPP");
    s_CoreLogger->set_level(spdlog::level::trace);
}

