#pragma once

#include "thread.h"

namespace wd
{

class TaskQueue;

class Producer
: public Thread
{
public:
    Producer(TaskQueue& t) : _taskQue(t) {}
private:
    void run() override;
    TaskQueue& _taskQue;
};

}
