#include <iostream>

#ifdef __cplusplus
extern "C"
{
#endif
int add(int a, int b)
{
    return a + b;
}
double add(double a, double b)
{
    return a + b;
}
#ifdef __cplusplus
}
#endif

int main()
{
    std::cout << "a + b = " << add(1.2, 3.8) << std::endl;
    return 0;
}

