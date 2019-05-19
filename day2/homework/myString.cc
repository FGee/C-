#include "myString.h"

String::String()
{
    _pstr = NULL;
    cout << "String" << endl;
}

String::String(const char *pstr)
{
    _pstr = new char[strlen(pstr) + 1];
    strcpy(_pstr, pstr);
    cout << "String(const char *pstr)" << endl;
}

String::String(const String & rhs)
{
    _pstr = new char[strlen(rhs._pstr) + 1];
    strcpy(_pstr, rhs._pstr);
    cout << "String(const String &rhs)" << endl;
}

String::~String()
{
    delete [] _pstr;
    cout << "~String" << endl;
}

void String::print()
{
    printf("str = %s\n", _pstr);
}
