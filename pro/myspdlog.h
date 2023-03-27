#ifndef MYSPDLOG_H
#define MYSPDLOG_H 
#include "spdlog/spdlog.h"
#include <spdlog/sinks/rotating_file_sink.h>


#define SPD_DEBUG(...) SPDLOG_LOGGER_DEBUG(spdlog::get("file_logger"), __VA_ARGS__)
#define SPD_LOG(...) SPDLOG_LOGGER_INFO(spdlog::get("file_logger"), __VA_ARGS__)
#define SPD_WARN(...) SPDLOG_LOGGER_WARN(spdlog::get("file_logger"), __VA_ARGS__)
#define SPD_ERROR(...) SPDLOG_LOGGER_ERROR(spdlog::get("file_logger"), __VA_ARGS__)


class MySpdlog
{
    private:
        MySpdlog();
        ~MySpdlog();
        MySpdlog(const MySpdlog&) = delete;
        MySpdlog& operator= (const MySpdlog&) = delete;
        static MySpdlog* m_instance;  
        bool InitSpdlog();

    public:
        static MySpdlog* GetInstance();
        static void delInstance();
        static bool ret;
};

#endif