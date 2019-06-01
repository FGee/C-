#include <iostream>

using std::cout;
using std::endl;
using std::cin;

template <typename T>

T Max(T a, T b)
{
    return (a > b) ? : a, b;
}

int main()
{
    int ia, ib;
    ia = 5;
    ib = 9;

    cout << "int max : " << Max(ia, ib) << endl; //implicit transform
    cout << "int max : " << Max<int>(ia, ib) << endl; //explicit transform
    

    double da, db;
    da = 11.11;
    db = 12.12;

    cout << "double max : " << Max(da, db) << endl; //implicit teansform
    cout << "double max : " << Max<double>(da, db) << endl; //explicit teansform

    return 0;
}

