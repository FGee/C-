#include "my_log.h"

int main()
{
    using namespace wd;
    //Mylog * log = Mylog::getInstance();

    //Mylog::getInstance()->info(prefix("hello,world!").c_str());
    //log->warn(prefix("open file fail!!!").c_str());
    //log->error(prefix("open file fail!!").c_str());
    //log->debug(prefix("open file fail!").c_str());

    LogInfo("hello, world!");

    const char* str = "world";
    int a = 5;

    LogDebug("hello %d %s", a, str);

    wd::Mylog::destory();


    return 0;
}
