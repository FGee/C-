#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <string.h>

#include <iostream>

using std::cout;
using std::endl;

class String 
{
public:
    String();
    String(const char *pstr);
    String(const String & rhs);
    String & operator=(const String & rhs)
    {
        if (this != &rhs) {
            delete [] _pstr;
            _pstr = new char[strlen(rhs._pstr) + 1];
            strcpy(_pstr, rhs._pstr);
        }
        cout << "operator=" << endl;
        return *this;
    }
    
    ~String();

    void print();

private:
    char * _pstr;
};
#endif
