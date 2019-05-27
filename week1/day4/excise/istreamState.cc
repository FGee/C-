#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void printCinStatus()
{
    cout << "cin's badbit = " << cin.bad() << endl
        << "cin's failbit = " << cin.fail() << endl
        << "cin's eofbit = " << cin.eof() << endl
        << "cin's goodbit = " << cin.good() << endl;
}

int main()
{
    int num = 13;

    while(cin >> num, !cin.eof()) {
        printCinStatus();
        cout << "num = " << num << endl;
        if (cin.fail()) {
            cin.clear();
            printCinStatus();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    printCinStatus();
    cin.clear();
    printCinStatus();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string str;
    cin >> str;
    cout << "string = " << str << endl;


    return 0;
}

