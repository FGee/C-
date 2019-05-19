#include <iostream>

int add(int a= 2, int b = 3);

int main()
{
    std::cout << "a + b = " << add() << std::endl;
    return 0;
}

int add(int a, int b)
{
    return a + b;
}
