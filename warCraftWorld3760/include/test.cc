#include "config.h"

#include <iostream>
#include <fstream>

using namespace warcraft;
using namespace std;

void readFromFile(const char* fileName)
{
    ifstream ifs;
    ifs.open(fileName, ios::in);

    if (ifs.fail()) {
        cout << ">> file open fail! <<" << endl; 
    }
    Config* pConfig = Config::getInstance();
    pConfig->loadFromIfstream(ifs);
    pConfig->startTest();

    //pConfig->printConfig();

    ifs.close();
}

int main()
{
    readFromFile("config.txt");

    return 0;
}

