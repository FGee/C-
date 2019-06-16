#include "thread.h"

#include <time.h>
#include <stdio.h>

#include <memory>

using namespace wd;

class MyTask
{
public:
    void process(int cnt)
    {
        ::srand(::clock());
        while(cnt--) {
            cout << "threadName :  " << threadName
                << " random num : " << ::rand() % 100 
                << endl;
        }
    }
private:
};

int main()
{
    MyTask task;
    
    shared_ptr<Thread> spThread( new
        //Thread(bind(&MyTask::process, &task, 5), "child thread one");
        Thread(bind(&MyTask::process, task, 5)));
    spThread->start();
    spThread->join();
    
    threadName = "main thread";
    cout << ">> Thread name: " << threadName << endl;

    return 0;
}
