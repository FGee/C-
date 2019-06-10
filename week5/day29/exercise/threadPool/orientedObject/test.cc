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

    unique_ptr<Task> upTask(new MyTask());

    int cnt = 10;
    while (cnt--) {
        upMypool->addTask(upTask.get());
        sleep(1);
    }

    sleep(10);

    upMypool->stop();

    return 0;
}

