#include <iostream>

using std::cout;
using std::endl;
using std::cin;

//int add(int a, int b)
//{
//    cout << "normal" << endl;
//    return a + b;
//}

template <typename T>
T add(T a, T b)
{
    cout << "template func" << endl;
    return a + b;
}

int main()
{
    int a = 5, b = 8;
    cout << add(a, b) << endl;

    return 0;
}

