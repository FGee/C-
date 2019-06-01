#include <iostream>

using std::cout;
using std::endl;
using std::cin;

template <typename T, int NUM>

T fun(T a)
{
    return a * NUM;
}

int main()
{
    cout << fun<int, 4>(3) << endl;

    return 0;
}

