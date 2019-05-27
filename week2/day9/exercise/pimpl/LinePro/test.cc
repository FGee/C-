#include "Line.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    Line ln(1, 1, 5, 5);

    ln.printLine();
    
    cout << "distance: " << ln.distance() << endl;


    return 0;
}
