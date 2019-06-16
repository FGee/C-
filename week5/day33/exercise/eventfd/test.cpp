#include "eventfd.h"

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
        cout << ">> get a random number : " << rand() % 100 << endl;
    }
};

int main()
{
    shared_ptr<EventFd> spEvent(new
        EventFd(bind(&CallBack::process, CallBack())));

    spEvent->start();

    sleep(20);

    spEvent->stop(); // 无法自行执行到这里，需要其它线程的调用

    return 0;
}

