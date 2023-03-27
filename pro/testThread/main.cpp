
#include <iostream>
#include <thread>

void thread1()
{
    //Add test1(1,2);
    //for(int t = 0 ;t < 1000 ;t ++)
    //{
    //    test1.ret();
    //}
    std::cout <<"1------"<<std::endl;


}
void thread2()
{
    //Sub test2(1,2);
    //for(int t = 0 ;t < 1000 ;t ++)
    //{
    //    test2.ret(); 
    //}
     std::cout <<"12------"<<std::endl;
}
int main()
{
    std::thread t1(thread1);
    t1.join();
}