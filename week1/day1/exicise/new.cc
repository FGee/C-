#include <iostream>

using std::cout;
using std::endl;

void test()
{
    int * pint = (int*)malloc(sizeof(int));
    *pint = 10;
    cout << "pint" << *pint << endl;

    free(pint);
}

void test1()
{
    int * pint = new int(10);
    cout << "*pint = " << *pint << endl;

    delete pint;
    int * parray = new int[10]();
    for(int idx = 0; idx != 10; ++idx) {
        cout << parray[idx] << " ";
    }
    cout << endl;

    delete [] parray;
}

int main()
{
    test1();
    return 0;
}

