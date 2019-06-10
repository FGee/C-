#pragma once

#include "thread.h"

namespace wd
{

class TaskQueue;

class Producer
{
public:
    void produce(TaskQueue&);
};

}
