#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

template <typename T>
T add(const T& a, const T& b) 
{
    return a + b;
}

int main()
{
    int a = 5;
    int b = 6;
    cout << "int: a + b = " << add(a, b) << endl;

    double da = 11.11;
    double db = 12.12;
    cout << "double: da + db = " << add(da, db) << endl;

    string sa("hello");
    string sb(", world");
    cout << "string: sa + sb = " << add(sa, sb) << endl;

    return 0;
}

