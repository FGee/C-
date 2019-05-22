#include "my_string.h"

#include <vector>
#include <string.h>

//using namespace wd;
using std::cout;
using std::endl;

String::String() : _pstr(nullptr) { cout << "String()" << endl; }

String::String(const char* c_str) : _pstr(new char[strlen(c_str) + 1]())
{
    strcpy(_pstr, c_str); 
    cout << "String(const char *)" << endl;
}

String::String(const String &rhs) : _pstr(new char[strlen(rhs._pstr) + 1]())
{
    strcpy(_pstr, rhs._pstr); 
    cout << "String(const String &rhs)" << endl;
}

String::~String()
{
    delete [] _pstr;
    cout << "~String()" << endl;
}

String & String::operator=(const String &rhs)
{
    if (*this != rhs) {
        delete [] _pstr;
        _pstr = new char[strlen(rhs._pstr) + 1]();
        strcpy(_pstr, rhs._pstr);
    }
    cout << "String & String::operator=(const String &rhs)" << endl;
    return *this;
}

String & String::operator=(const char * c_str)
{
    if (_pstr != c_str) {
        delete [] _pstr;
        _pstr = new char[strlen(c_str) + 1]();
        strcpy(_pstr, c_str);
    } 
    cout << "String & String::operator=(const char * c_str)" << endl;
    return *this;
}

String & String::operator+=(const String &rhs)
{
    char * tempStr = new char[size() + rhs.size() + 1]();
    //strcat(tempStr, _pstr);
    //strcat(tempStr, rhs._pstr);
    sprintf(tempStr, "%s%s", _pstr, rhs._pstr);
    delete [] _pstr;
    _pstr = tempStr;
    cout << "String & String::operator+=(const String &rhs)" << endl;
    return *this;
}

String & String::operator+=(const char * c_str)
{
    char * tempStr = new char[size() + strlen(c_str) + 1]();
    sprintf(tempStr, "%s%s", _pstr, c_str);
    delete [] _pstr;
    _pstr = tempStr;
    cout << "String & String::operator+=(const char * c_str)" << endl;
    return *this;
}

std::size_t String::size() const
{
    cout << "std::size_t String::size() const" << endl;
    if (nullptr == _pstr) {
        return 0;
    }
    return strlen(_pstr);
}

char & String::operator[](std::size_t index)
{
    cout << "char & String::operator[](std::size_t index)" << endl;
    if (index < size()) {
        return _pstr[index];
    } else {
        cout << "index over range!!!" << endl;
        static char overflowVal = '\0';
        return overflowVal;
    }
}

const char & String::operator[](std::size_t index) const
{
    cout << "const char & String::operator[](std::size_t index) const" << endl;
    if (index < size()) {
        return _pstr[index];
    } else {
        cout << "index over range!!!" << endl;
        static char overflowVal = '\0';
        return overflowVal;
    }
}

const char * String::c_str() const
{
    cout << "const char * String::c_str() const" << endl;
    return _pstr;
}

bool operator==(const String & lhs, const String & rhs) 
{
    cout << "bool operator==(const String & lhs, const String & rhs)" << endl;
    return !strcmp(lhs.c_str(), rhs.c_str());
}

bool operator!=(const String & lhs, const String & rhs)
{
    cout << "bool operator!=(const String & lhs, const String & rhs)" << endl;
    return strcmp(lhs.c_str(), rhs.c_str());
}

bool operator<(const String & lhs, const String & rhs)
{
    cout << "bool operator<(const String & lhs, const String & rhs)" << endl;
    if (strcmp(lhs.c_str(), rhs.c_str()) < 0) {
        return true;
    } else {
        return false;
    }
}

bool operator>(const String & lhs, const String & rhs)
{
    cout << "bool operator>(const String & lhs, const String & rhs)" << endl;
    if (strcmp(lhs.c_str(), rhs.c_str()) > 0) {
        return true;
    } else {
        return false;
    }
}

bool operator<=(const String & lhs, const String & rhs)
{
    cout << "bool operator<=(const String & lhs, const String & rhs)" << endl;
    if (strcmp(lhs.c_str(), rhs.c_str()) <= 0) {
        return true;
    } else {
        return false;
    }
}

bool operator>=(const String & lhs, const String & rhs)
{
    cout << "bool operator>=(const String & lhs, const String & rhs)" << endl;
    if (strcmp(lhs.c_str(), rhs.c_str()) >= 0) {
        return true;
    } else {
        return false;
    }
}

std::ostream & operator<<(std::ostream &os, const String &s)
{
    cout << "std::ostream & operator<<(std::ostream &os, const String &s)" << endl;
    os << s.c_str();
    return os;
}

std::istream & operator>>(std::istream &is, String &s)
{
    std::vector<char> buf;
    buf.reserve(1024);

    char ch;
    while('\n' != (ch = is.get())) {
        buf.push_back(ch);
    }

    delete [] s._pstr;
    s._pstr = new char[buf.size() + 1]();
    strncpy(s._pstr, &buf[0], buf.size());

    return is;
    //char tempStr[50] = { 0 };
    //is >> tempStr;
    //delete [] s._pstr;
    //s._pstr = new char[strlen(tempStr) + 1]();
    //strcpy(s._pstr, tempStr);
    //cout << "std::istream & operator>>(std::istream &is, String &s)" << endl;
    //return is;
}

String operator+(const String & lhs, const String &rhs)
{
    String temp;
    temp += lhs;
    temp += rhs;
    cout << "String operator+(const String & lhs, const String &rhs)" << endl;
    return temp;
}

String operator+(const String & lhs, const char * c_str)
{
    String temp;
    temp += lhs;
    temp += c_str;
    cout << "String operator+(const String & lhs, const char * c_str)" << endl;
    return temp;
}

String operator+(const char * c_str, const String & rhs)
{
    String temp;
    temp += c_str;
    temp += rhs;
    cout << "String operator+(const char * c_str, const String & rhs)" << endl;
    return temp;
}













