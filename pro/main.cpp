#include "myspdlog.h"
#include "test.h"
#include <unistd.h>
#include <iostream>
#include <thread>

void thread1()
{
    Test test1(1);
    for(int t = 0 ;t < 1000000 ;t ++)
    {
        test1.ret();
        //sleep(1);
    }
}
void thread2()
{
    Test test2(2);
    for(int t = 0 ;t < 100000 ;t ++)
    {
       test2.ret();
       //sleep(1); 
    }
}
void thread3()
{
    Test test3(3);
    for(int t = 0 ;t < 100000;t ++)
    {
       test3.ret();
       //sleep(1); 
    }
}
int main()
{
    MySpdlog *p = MySpdlog::GetInstance();
    if(!p->ret) 
    {
        MySpdlog::delInstance();
        return 0;
    }
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread t3(thread3);
    t1.join();
    t2.join();
    t3.join();
    MySpdlog::delInstance();
}