#include "taskQueue.h"
#include "producer.h"
#include "consumer.h"

#include <unistd.h>

#include <iostream>
#include <memory>

using namespace wd;
using namespace std;

int main()
{
    TaskQueue taskQueue(10);

    unique_ptr<Producer> upPro1(new Producer(taskQueue));
    unique_ptr<Producer> upPro2(new Producer(taskQueue));
    unique_ptr<Consumer> upCon1(new Consumer(taskQueue));
    unique_ptr<Consumer> upCon2(new Consumer(taskQueue));

    upPro1->start();
    upPro2->start();

    upCon1->start();
    upCon2->start();

    sleep(50);

    upPro1->join();
    upPro2->join();
    upCon1->join();
    upCon2->join();

    return 0;
}

