#include "my_string.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    String str1;
    cin >> str1;
    cout << str1 << endl;

    String str2("hello, world!");
    cout << str2 << endl;
    
    String str3(str2);
    cout << str3 << endl;

    String str4 = "how are you?";
    cout << str4 << endl;

    String str5 = str2 + str4;
    cout << str5 << endl;
    
    String str6 = str4 + " Mary";
    cout << str6 << endl;

    String str7 = "Mike:" + str4;
    cout << str7 << endl;

    cout << "str2[3]" << str2[3] << endl;

    cout << "str2.c_str()" << str2.c_str() << endl;

    cout << "str2 >= str4" << (str2 >= str4) << endl;

    return 0;
}

