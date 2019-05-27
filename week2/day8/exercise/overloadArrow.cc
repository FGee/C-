#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Data {
public:
    Data(int ix = 0) : _ix(ix) { cout << "Data()" << endl; }
    ~Data() { cout << "~Data()" << endl; }
    int ix() const
    {
        //cout << "ix()" << endl; 
        return _ix; 
    }
private:
    int _ix;
};

class MiddleLayer {
public:
    MiddleLayer(Data* pData) : _pData(pData) { cout << "MiddleLayer()" << endl; }
    ~MiddleLayer()
    {
        cout << "~MiddleLayer()" << endl;
        if (_pData) {
            delete _pData;
        }
    }
    Data* operator->() 
    {
        //cout << "Data* operator->()" << endl;
        return _pData; 
    }

    Data& operator*()
    {
        return *_pData;
    }

private:
    Data* _pData;
};

class ThriLayer {
public:
    ThriLayer(MiddleLayer* pMid) : _pMid(pMid) { cout << "ThriLayer()" << endl; }
    ~ThriLayer() 
    {
        cout << "~ThriLayer()" << endl; 
        if (_pMid) {
            delete _pMid;
        }
    }
    MiddleLayer& operator->()//don't delete & 
    {
        //cout << "MiddleLayer operator->()" << endl;
        return *_pMid;
    }
private:
    MiddleLayer* _pMid;
};

int main()
{
    cout << ">>--------------test one----------------------<<" << endl;

    MiddleLayer pData(new Data(8));
    cout << "pData->ix() = " << pData->ix() << endl;
    cout << "pData.operator->()->ix() = " << pData.operator->()->ix() << endl;
    
    cout << ">>--------------test one----------------------<<" << endl;
    
    ThriLayer ppData(new MiddleLayer(new Data(19)));

    cout << "ppData->ix() = " << ppData->ix() << endl;
    cout << "(ppData.operator->()).operator->()->ix() = " << ((ppData.operator->()).operator->())->ix() << endl;
    
    cout << ">>--------------test three----------------------<<" << endl;
    cout << "(*pData).ix() = " << (*pData).ix() << endl;
    cout << "pData.operator*().ix() = " << pData.operator*().ix() << endl;

    return 0;
}
