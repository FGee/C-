#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    double dval = 2.333;
    //int& a = dval; // <==> const int temp = dval; int& a = temp;(this is not legal)
    const int& a = dval;// <==> const int temp = dval; const int& a = temp;
    cout << "const int& a = " << a << endl;
    //int&& rvalue = a;
    int&& rvalue = dval; 
    cout << "int&& rvalue = " << rvalue << endl;
    
    return 0;
}

