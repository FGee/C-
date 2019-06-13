#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    
    char* pCh = (char*)&a;

    if (1 == *pCh) {
        cout << "small edge" << endl;
    } else {
        cout << "big edge" << endl;
    }

    return 0;
}

