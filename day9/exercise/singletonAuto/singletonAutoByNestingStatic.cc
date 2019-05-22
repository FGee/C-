#include <iostream>

using std::cout;
using std::endl;

class Singleton {
    class AutoRelase {
    public:
        AutoRelase()
        {
            cout << "AutoRelase()" << endl;
        }
        ~AutoRelase()
        {
            destroy();
            cout << "~AutoRelase()" << endl;
        }
    private:
    };
public:
    static Singleton* getInstance()
    {
        if (nullptr == _pSingleton) {
            _pSingleton = new Singleton();
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
    static AutoRelase _autoRelase;
    static Singleton* _pSingleton;
};

Singleton::AutoRelase Singleton::_autoRelase;

//Singleton* Singleton::_pSingleton = nullptr; //lazy man modle

Singleton* Singleton::_pSingleton = Singleton::getInstance(); //full man modle to avoid the mulity thread 

static int a;

int main()
{
    ::a = 9;

    Singleton::getInstance();

    return 0;
}
