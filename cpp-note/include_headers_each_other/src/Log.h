#pragma once
#include <spdlog/spdlog.h>
#include <memory>

class Log
{
public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& getCoreLogger(){ return s_CoreLogger; }

private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;

};


#define LOG_WARN(...) ::Log::getCoreLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Log::getCoreLogger()->error(__VA_ARGS__)
#define LOG_TRACE(...) ::Log::getCoreLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...) ::Log::getCoreLogger()->info(__VA_ARGS__)
//#define LOG_FATAL(...) ::Log::getCoreLogger()->fatal(__VA_ARGS__)



