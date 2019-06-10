#include "consumer.h"
#include "taskQueue.h"

#include <unistd.h>

namespace wd
{

void Consumer::run()
{
    while (1) {
        cout << "Consumer: " << pthread_self() << " gets the num: "
            << _taskQue.pop() << endl;
        sleep(2);
    }
}

}
