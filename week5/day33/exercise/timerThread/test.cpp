#include "timerfdThread.h"

#include <time.h>
#include <unistd.h>

#include <iostream>
#include <memory>

using namespace std;
using namespace wd;

struct Task
{
    void process()
    {
        ::srand(::clock());
        cout << ">> Thread Name : " << threadName
            << " get a random number : " << rand() % 100 << endl;
    }
};

int main()
{
    shared_ptr<TimerfdThread> spTimerfdThread(new
        TimerfdThread(3, 6, bind(&Task::process, Task())));
    
    spTimerfdThread->start();

    sleep(12);

    spTimerfdThread->stop();

    cout << ">> Thread Name : " << threadName << endl;

    return 0;
}

