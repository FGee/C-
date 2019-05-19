#include "my_log.h"

int main()
{
    Mylog * log = Mylog::getInstance();
    log->warn("open file fail");
    log->info("hello");

    log->destory();
    return 0;
}
