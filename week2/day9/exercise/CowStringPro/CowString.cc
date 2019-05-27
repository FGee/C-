#include <string.h>

#include <iostream>

using std::cout;
using std::endl;

class CowString {
public:
    class MyChar {
    public:
        MyChar(CowString* pcs, int index) : _pCow(pcs), _index(index)
        {
            //cout << "MyChar()" << endl;
        }
        operator char() const 
        {
            return _pCow->_pstr[_index];
        }
        MyChar& operator=(const MyChar& rcs)
        {
            char* tempPtr = new char[4 + 1 + _pCow->size()]() + 4;
            strcpy(tempPtr, _pCow->_pstr);
            _pCow->refDecrease();
            _pCow->_pstr = tempPtr;
            _pCow->refInit();

            _pCow->_pstr[_index] = ((rcs._pCow)->_pstr)[rcs._index];
            return *this;
        }
        MyChar& operator=(char ch)
        {
            char* tempPtr = new char[4 + 1 + _pCow->size()]() + 4;
            strcpy(tempPtr, _pCow->_pstr);
            _pCow->refDecrease();
            _pCow->_pstr = tempPtr;
            _pCow->refInit();
            
            _pCow->_pstr[_index] = ch;
            return *this;
        }
    private:
        CowString* _pCow;
        int _index;
    };
public:
    char* c_str() const { return _pstr; }
    int size() const { return strlen(_pstr); }
    int refGet() const { return *(int*)(_pstr - 4); }

    CowString() : _pstr(new char[4 + 1]() + 4)
    {
        cout << "CowString()" << endl;
        refInit();
    }

    CowString(const char *str) : _pstr(new char[4 + 1 + strlen(str)]() + 4)
    {
        cout << "CowString(const char*)" << endl;
        strcpy(_pstr, str);
        refInit();
    }

    CowString(const CowString & rhs) 
    {
        cout << "CowString(const CowString & rhs)" << endl;
        _pstr = rhs._pstr;
        refIncrease();
    }

    CowString& operator=(CowString & rhs)
    {
        cout << "CowString& operator=(CowString & rhs)" << endl;
        if (_pstr != rhs._pstr) {
            release();
            _pstr = rhs._pstr;
            refIncrease();
        }
        return *this;
    }

    MyChar operator[](int index)
    {
        //cout << "char operator[](int index)" << endl;
        if (index >= 0 && index < size()) {
            return MyChar(this, index);
        } else {
            cout << "over range!!!" << endl;
            return MyChar(this, -1);  //have problem
        }
    }

    friend std::ostream& operator<<(std::ostream & os, const CowString& cstr);

    ~CowString()
    {
        cout << "~CowString()" << endl;
        release();
    }

private:
    void refInit() { *(int*)(_pstr - 4) = 1; }
    void refIncrease() { ++*(int*)(_pstr - 4); }
    void refDecrease() { --*(int*)(_pstr - 4); }
    void release() 
    {
        refDecrease();
        if (0 == refGet()) {
            delete (_pstr - 4);
        }
    }

private:
    char* _pstr;
};

std::ostream& operator<<(std::ostream & os, const CowString& cstr)
{
    os << cstr.c_str();
    return os;
}

int main()
{
    CowString str1;
    CowString str2("hello,world!");
    CowString str3;

    str3 = str2;
    CowString str4(str3);

    cout << endl << "----------one--------------" << endl;

    cout << "str1=" << str1 << endl;
    cout << "str2=" << str2 << endl;
    cout << "str3=" << str3 << endl;
    cout << "str4=" << str4 << endl;
 
    printf("str1.cstr()=%p\n", str1.c_str());
    printf("str2.cstr()=%p\n", str2.c_str());
    printf("str3.cstr()=%p\n", str3.c_str());
    printf("str4.cstr()=%p\n", str4.c_str());

    cout << "str1.refGet()" << str1.refGet() << endl;
    cout << "str2.refGet()" << str2.refGet() << endl;
    cout << "str3.refGet()" << str3.refGet() << endl;
    cout << "str4.refGet()" << str4.refGet() << endl;
    
    cout << endl << "----------three--------------" << endl;

    cout << "str2=" << str2 << endl;

    cout << "str2[4]=" << str2[4] << endl;
 
    printf("str2.cstr()=%p\n", str2.c_str());

    cout << "str2.refGet()" << str2.refGet() << endl;
    
    cout << endl << "----------two--------------" << endl;

    str2[1] = 'H';
    str3[1] = 'I';
    str4[1] = 'J';

    cout << "str1=" << str1 << endl;
    cout << "str2=" << str2 << endl;
    cout << "str3=" << str3 << endl;
    cout << "str4=" << str4 << endl;
 
    printf("str1.cstr()=%p\n", str1.c_str());
    printf("str2.cstr()=%p\n", str2.c_str());
    printf("str3.cstr()=%p\n", str3.c_str());
    printf("str4.cstr()=%p\n", str4.c_str());

    cout << "str1.refGet()" << str1.refGet() << endl;
    cout << "str2.refGet()" << str2.refGet() << endl;
    cout << "str3.refGet()" << str3.refGet() << endl;
    cout << "str4.refGet()" << str4.refGet() << endl;
    
    return 0;
}
