#include "producer.h"
#include "taskQueue.h"

#include <stdio.h>
#include <time.h>
#include <unistd.h>

namespace wd
{

void Producer::produce(TaskQueue& taskQue)
{
    ::srand(::clock());
    while (1) {
        taskQue.push(rand() % 100);
        cout << "Producer: " << pthread_self() << " push the num" << endl;
        sleep(1);
    }
}

}
