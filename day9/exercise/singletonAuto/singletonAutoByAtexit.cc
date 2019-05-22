#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;

class Singleton {
public:
    static Singleton* getInstance()
    {
        if (nullptr == _pSingleton) {
            _pSingleton = new Singleton();
            atexit(destroy);
        }
        return _pSingleton;
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
    static Singleton* _pSingleton;
};

//Singleton* Singleton::_pSingleton = nullptr; //lazy man modle

Singleton* Singleton::_pSingleton = Singleton::getInstance(); //full man modle to avoid the mulity thread 

int main()
{
    //Singleton::getInstance();

    //Singleton::getInstance()->destroy();

    return 0;
}
