#include "stack.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

template <template <class Type, int NUM> class TypeClass, class T1, int N>
void disp()
{
    TypeClass<T1, N> ob;
    cout << ob.returnNum() << endl;
}

int main()
{
    disp<Stack, int, 8>();

    return 0;
}

