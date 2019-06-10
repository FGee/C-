#include "consumer.h"
#include "taskQueue.h"

#include <unistd.h>

namespace wd
{

void Consumer::consume(TaskQueue& taskQue)
{
    while (1) {
        cout << "Consumer: " << pthread_self() << " gets the num: "
            << taskQue.pop() << endl;
        sleep(2);
    }
}

}
