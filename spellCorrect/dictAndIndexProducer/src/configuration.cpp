#include "../include/configuration.h"
#include "../include/macro.h"

#include <fstream>
#include <sstream>
#include <iostream>

namespace wd
{

Configuration* Configuration::pConfiguration = nullptr;

Configuration::AutoRelease Configuration::_auto;

void Configuration::loadConfigFile(const char* fileName)
{
    ifstream ifs;
    ifs.open(fileName, ios::in);
    if (ifs.fail()) { ERROR_EXIT("open"); }

    string line;
    while (getline(ifs, line)) {
        istringstream iss(line);
        string item;
        string value;
        iss >> item;
        iss >> value;

        pair<Item, Value> itemNew(item, value);
        _spConfigMultimap->insert(itemNew);
    }
}

//inline
//shared_ptr<multimap<Configuration::Item, Configuration::Value>> Configuration::getConfigMultimap()
//{
//    return _spConfigMultimap;
//}

inline
Configuration::AutoRelease::AutoRelease()
{
    cout << "AutoRelease()" << endl;
}

Configuration::AutoRelease::~AutoRelease()
{
    if (nullptr != pConfiguration) {
        delete pConfiguration;
    }
    cout << "~AutoRelease()" << endl;
}

Configuration* Configuration::getInstance()
{
    if (nullptr == pConfiguration) {
        pConfiguration = new Configuration();
        //(void)_auto;
    }
    return pConfiguration;
}

inline
Configuration::Configuration() : _spConfigMultimap(new multimap<Item, Value>())
{ cout << "Configuration()" << endl; }

inline
Configuration::~Configuration() { cout << "~Configuration()" << endl; }

}
