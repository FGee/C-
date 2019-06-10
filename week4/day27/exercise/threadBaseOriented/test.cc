#include "thread.h"

#include <time.h>
#include <stdio.h>

using namespace wd;

class MyTask
{
public:
    void process(int cnt)
    {
        ::srand(::clock());
        while(cnt--) {
            cout << "thId: " << pthread_self()
                << "random num : " << ::rand() % 100 
                << endl;
        }
    }
private:
};

int main()
{
    MyTask task;
    //Thread myThread(bind(&MyTask::process, MyTask, 5));
    Thread myThread(bind(&MyTask::process, &task, 5));
    myThread.start();
    myThread.join();

    return 0;
}
