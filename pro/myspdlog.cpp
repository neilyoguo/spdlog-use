#include <iostream>
#include "myspdlog.h"

#define MAX_FILES 10             //10个文件
#define MAX_SIZE 1024*1024*10    //10M

MySpdlog*  MySpdlog::m_instance(new MySpdlog());
bool MySpdlog::ret = false;
MySpdlog::MySpdlog()
{
    ret = InitSpdlog();
}
MySpdlog::~MySpdlog()
{
}
MySpdlog* MySpdlog::GetInstance()
{
    return m_instance;
}
void MySpdlog::delInstance()
{
    if(m_instance != nullptr)
    {
        delete m_instance;
        m_instance = nullptr;
    }
    spdlog::drop_all();
}

bool MySpdlog::InitSpdlog()
{
    try
    {
        auto rotating_logger = spdlog::rotating_logger_mt("file_logger", "log.txt", MAX_SIZE, MAX_FILES);
        rotating_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e][%s,%!,%#]:%v");
        return true;
    }  
    catch(const spdlog::spdlog_ex& ex)
    {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
        return false;
    }
}
