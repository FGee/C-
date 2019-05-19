#include <iostream>

using std::cout;
using std::endl;
using std::string;

void test0()
{
    char str[] = "hello,world";
    printf("str = %s\n", str);

    const char * pstr = "hello,world";
    printf("pstr = %s\n", pstr);
}

void test1()
{
    int number(1);
    cout << "number = " << number << endl;

    string s1 = "hello, ";
    string s2("world");
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    const char* pstr = s1.c_str();
    const char* pstr2 = s1.data();
    printf("pstr = %s\n", pstr);
    printf("pstr2 = %s\n", pstr2);

    cout << "s2.size()" << s2.size() << endl;
    cout << "s2.lenth" << s2.length() << endl;

    for(size_t idx = 0; idx != s2.size(); ++idx) {
        cout << s2[idx] << endl;
    }

    string s3 = s1 + s2;
    cout << "s3 = " << s3 << endl;
    s3.append(",shenzhen");
    cout << "s3 = " << s3 << endl;
    s3.append(3, 'z');
    cout << "s3 = " << s3 << endl;
    s3.append(s1);
    cout << "s3 = " << s3 << endl;

    size_t pos = s3.find('s');
    string s4 = s3.substr(pos, 8);
    cout << "s4 = " << s4 << endl;
}

int main()
{
    test1();

    return 0;
}

