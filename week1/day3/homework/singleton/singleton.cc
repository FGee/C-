#include <stdio.h>

#include <iostream>

using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton * getInstance()
    {
        if (NULL == pSingleton) {
            pSingleton = new Singleton;
        }
        return pSingleton;
    }

    static void destroy()
    {
        if (NULL != pSingleton) {
            delete pSingleton;
        }
    }

    void print() const 
    {
        printf("pSingleton = %p\n", pSingleton);
    }
private:
    Singleton();
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }
private:
    static Singleton* pSingleton;
};

Singleton::Singleton() 
{
    cout << "Singleton()" << endl;
}

Singleton* Singleton::pSingleton  = NULL;

int main()
{
    Singleton * pSingleton1 =  Singleton::getInstance();
    pSingleton1->print();
    Singleton * pSingleton2 = Singleton::getInstance();
    pSingleton2->print();
    pSingleton1->destroy();

    return 0;


}

