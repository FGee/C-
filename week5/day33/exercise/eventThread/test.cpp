#include "eventThread.h"

#include <time.h>
#include <unistd.h>

#include <iostream>
#include <memory>

using namespace std;
using namespace wd;

struct CallBack
{
    void process()
    {
        ::srand(::clock());
        cout << ">> Thread Name: " << threadName
            << " get a random number : " << rand() % 100 << endl;
    }
};

int main()
{
    shared_ptr<EventThread> spEventThread(new
        EventThread(bind(&CallBack::process, CallBack()), "Eventfd Thread"));

    spEventThread->start();

    threadName = "Main Thread";
    int cnt = 20;
    while (--cnt) {
        cout << "Thread Name: " << threadName
            << " cnt : " << cnt << endl;
        spEventThread->weak();
        sleep(1);
    }

    spEventThread->stop(); 

    return 0;
}

