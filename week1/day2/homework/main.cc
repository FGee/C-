#include "myString.h"

int main()
{
    String str1;
    str1.print();

    String str2 = "Hello,world";
    String str3("wangdao");

    str2.print();
    str3.print();
    
    String str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();

    String str5(str2);
    str5.print();

    return 0;
}

