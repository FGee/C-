#include <string.h>

#include <iostream>

using namespace std;

class String
{
public:
    String(const char* c_str) : _pstr(new char[strlen(c_str) + 1]())
    {
        cout << "String(const char*)" << endl;
        strcpy(_pstr, c_str);
    }
    String(const String& rhs) : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String&)" << endl;
        strcpy(_pstr, rhs._pstr);
    }
    String(String&& rhs) : _pstr(rhs._pstr)
    {
        cout << "String(String&&)" << endl;
        rhs._pstr = nullptr;
    }
    String& operator=(const String& rhs)
    {
        cout << "String& operator=(const String& rhs)" << endl;
        if (this != &rhs) {
            delete [] _pstr;
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }
    String& operator=(String&& rhs) {
        cout << "String& operator=(String&& rhs)" << endl;
        if (this != &rhs) {
            delete [] _pstr;
            _pstr = rhs._pstr;
            rhs._pstr = nullptr;
        }
        return *this;
    }
    ~String() { cout << "~String()" << endl; }
    char* c_str()
    {
        return _pstr;
    }
private:
    char* _pstr;
};

int main()
{
    String str1("hello");
    
    //String str2(std::move(str1));

    //cout << str2.c_str() << endl;
    //cout << str1.c_str() << endl;

    String str3 = "world";
    cout << str3.c_str() << endl;

    str3 = str1;
    str3 = std::move(str1);
    cout << str3.c_str() << endl;
    cout << str1.c_str() << endl;



    return 0;
}

