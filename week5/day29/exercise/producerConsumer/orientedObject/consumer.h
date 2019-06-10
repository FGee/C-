#pragma once
#include "thread.h"

namespace wd
{

class TaskQueue;

class Consumer
: public Thread
{
public:
    Consumer(TaskQueue& t) : _taskQue(t) {}
private:
    void run() override;
    TaskQueue& _taskQue;
};

}
