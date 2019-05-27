#include "headquarter.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void test()
{
    int caseNo = 0;
    int initLife = 0;
    int sthArr[5] = { 0 };
    cin >> caseNo;
    cin >> initLife;
    for (int i = 0; i < 5; ++i) {
        cin >> sthArr[i];
    }
    Headquarter red(initLife, sthArr[0], sthArr[1], sthArr[2], sthArr[3], sthArr[4], "red");
    int redArr[5] = { 4, 3, 0, 1, 2 };
    red.setOrder(redArr);

    Headquarter blue(initLife, sthArr[0], sthArr[1], sthArr[2], sthArr[3], sthArr[4], "blue");
    int blueArr[5] = { 1, 2, 3, 0, 4 };
    blue.setOrder(blueArr);

    bool redStat, blueStat;
    redStat = blueStat = true;
    cout << "Case:" << caseNo << endl;
    while (redStat || blueStat) {
        redStat = red.produce(_time % 5);
        blueStat = blue.produce(_time % 5);
        ++_time;
    }
}

int main()
{
    test();

    return 0;
}

