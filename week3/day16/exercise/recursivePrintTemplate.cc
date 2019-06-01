#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void print()
{
    cout << endl;
}

template <typename T1>
void print(T1 t1)
{
    cout << t1 << endl;
    cout << "print(T1)" << endl;
}

template <typename T, typename...Args>
void print(T& t, Args...args)
{
    cout << t << " ";
    print(args...);
}

int main()
{
    print("ha", "hi", "hu", "he", "ho");

    return 0;
}

