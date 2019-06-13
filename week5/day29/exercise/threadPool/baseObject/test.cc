#include "threadPool.h"
#include "myTask.h"

#include <unistd.h>

#include <iostream>
#include <memory>

using namespace wd;
using namespace std;

int main()
{
    unique_ptr<ThreadPool> upMypool(new ThreadPool(4, 2));
    upMypool->start();

    int cnt = 10;
    while (cnt--) {
        upMypool->addTask(bind(&MyTask::process, MyTask()));
        sleep(1);
    }

    sleep(10);

    upMypool->stop();

    return 0;
}

