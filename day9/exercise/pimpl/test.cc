#include "Line.h"

int main()
{
    Line::Point pt;

    Line ln(1, 1, 5, 5);

    ln.print();
    
    cout << "distance: " << ln.distance() << endl;


    return 0;
}
