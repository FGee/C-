#include "taskQueue.h"
#include "producer.h"
#include "consumer.h"

#include <unistd.h>

#include <iostream>
#include <memory>
#include <functional>

using namespace wd;
using namespace std;

int main()
{
    TaskQueue taskQueue(10);
    
    Producer produce;
    Consumer consume;

    unique_ptr<Thread> upThPro1(new Thread(bind(&Producer::produce, &produce, ref(taskQueue))));
    unique_ptr<Thread> upThPro2(new Thread(bind(&Producer::produce, &produce, ref(taskQueue))));
    unique_ptr<Thread> upThCon1(new Thread(bind(&Consumer::consume, &consume, ref(taskQueue))));
    unique_ptr<Thread> upThCon2(new Thread(bind(&Consumer::consume, &consume, ref(taskQueue))));

    upThPro1->start();
    upThPro2->start();
    upThCon1->start();
    upThCon2->start();
    
    sleep(50);

    upThPro1->join();
    upThPro2->join();
    upThCon1->join();
    upThCon2->join();

    return 0;
}

