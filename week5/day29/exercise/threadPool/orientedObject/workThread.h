#include "thread.h"

namespace wd
{

class ThreadPool;

class WorkThread
: public Thread
{
public:
    WorkThread(ThreadPool& t)
        : _threadPool(t) {}
private:
    void run() override;
    ThreadPool& _threadPool;
};

}
