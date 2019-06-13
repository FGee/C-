#include <iostream>

using namespace std;

union Verify {
    int ival;
    char ch;
};

bool isSmallEdge() {
    Verify ver;
    ver.ival = 1;
    return ver.ch;
}

int main()
{
    if (isSmallEdge()) {
        cout << "small edge" << endl;
    } else {
        cout << "big edge" << endl;
    }

    return 0;
}

