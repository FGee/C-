#include "myTask.h"

#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#include <iostream>

using namespace std;

namespace wd
{

void MyTask::process()
{
    ::srand(::clock());
    cout << "thId : " << pthread_self()   
        << "    random number : " << rand() % 100 << endl;
    sleep(1);
}

}
