#pragma once
#include "thread.h"

namespace wd
{

class TaskQueue;

class Consumer
{
public:
    void consume(TaskQueue&);
};

}
