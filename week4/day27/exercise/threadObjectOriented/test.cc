#include "thread.h"

#include <time.h>
#include <unistd.h>

#include <iostream>

using namespace wd;
using std::cout;
using std::endl;
using std::cin;

class MyThread
: public Thread
{
public:
    ~MyThread() { cout << "~MyThread()" << endl; }
private:
    void run() override
    {
        ::srand(::clock());
        for (int i = 0; i < 5; ++i) {
            int randomNum = ::rand() % 100;
            cout << "threadId: " << pthread_self() << " : " << randomNum << " " << endl;
        }
    }
};

int main()
{
    MyThread my;
    //MyThread my1(my);
    //MyThread my2 = my;
    my.start();
    //my1.start();
    sleep(4);
    my.join();

    return 0;
}

