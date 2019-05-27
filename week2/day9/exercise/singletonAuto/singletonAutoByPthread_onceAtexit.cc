#include <stdlib.h>
#include <pthread.h>

#include <iostream>

using std::cout;
using std::endl;

class Singleton {
public:
    static Singleton* getInstance()
    {
        pthread_once(&_once_init, init);
        return _pSingleton;
    }
    
    static void init()
    {
        _pSingleton = new Singleton();
        atexit(destroy);
    }

    static void destroy()
    {
        delete _pSingleton;
    }
private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    }
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }
private:
    static pthread_once_t _once_init;
    static Singleton* _pSingleton;
};

pthread_once_t Singleton::_once_init = PTHREAD_ONCE_INIT;

Singleton* Singleton::_pSingleton = nullptr; //lazy man modle

//Singleton* Singleton::_pSingleton = Singleton::getInstance(); //full man modle to avoid the mulity thread 

int main()
{
    Singleton::getInstance();

    return 0;
}
