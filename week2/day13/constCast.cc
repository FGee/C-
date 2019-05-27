#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    cout << "*******const cival********" << endl;
    //cout << "*******cival********" << endl;
    const
        int cival = 666;
    const int* pci = &cival;
    cout << "cival = " << cival << endl;
    cout << "*pci = " << *pci << endl;
    cout << "pci: " << &pci << endl;
    cout << "address pci: " << &pci << endl;

    cout << "------------------after cast----------------------" << endl;
    *const_cast<int*>(pci) = 2333;
    cout << "cival = " << cival << endl;
    cout << "after const_cast *pci = " << *pci << endl;
    cout << "pci: " << &pci << endl;
    cout << "address pci: " << &pci << endl;

    return 0;
}

