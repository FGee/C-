#include <string.h>

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

template <typename T1, typename T2>
T1 add(T1 t1, T2 t2)
{
    return t1 + t2;
}

template <>
const char* add<const char*, const char*>(const char* str1, const char* str2)
{
    char* ptmp = new char[strlen(str1) + strlen(str2) + 1]();
    strcpy(ptmp, str1);
    strcat(ptmp, str2);

    return ptmp;
}

//template<typename T1, typename T2>// function template partition specialization is not allowed
//T1 add<T1, int>(T1 t1, int ival)
//{
//    return t1 + ival;
//}

int main()
{
    cout << "const char* str1 + const char* st2 = " << add<const char*, const char*>("hello", ", world") << endl;

    return 0;
}

