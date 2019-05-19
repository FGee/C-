#include "my_log.h"
#define __my_func_ my_func(__FILE__, __LINE__, __func__)

int main()
{
    Mylog * log = Mylog::getInstance();
    log->info("hello, world!", __func_info_);
    log->warn("open file fail!!!", __func_info_);

    log->destory();


    return 0;
}
