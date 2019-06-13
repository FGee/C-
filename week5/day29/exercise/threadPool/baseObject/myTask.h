#pragma once
#include "task.h"

namespace wd
{

class MyTask
: public Task
{
public:
    virtual
        void process() override;
};

}
