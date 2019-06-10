#include "workThread.h"
#include "threadPool.h"

namespace wd
{

void WorkThread::run()
{
    _threadPool.threadFunc();
}

}
