#include "test.h"
#include "myspdlog.h"
Test::Test(int t )
{
    this->t = t;
}

Test::~Test()
{

}

void Test::ret()
{
    SPD_LOG("test {3} is----------{0},{1},{2},", 12, "string", 1.244, t);
}