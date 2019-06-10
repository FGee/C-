#include "producer.h"
#include "taskQueue.h"

#include <stdio.h>
#include <time.h>
#include <unistd.h>

namespace wd
{

void Producer::run()
{
    ::srand(::clock());
    while (1) {
        _taskQue.push(rand() % 100);
        cout << "Producer: " << pthread_self() << " push the num" << endl;
        sleep(1);
    }
}

}
