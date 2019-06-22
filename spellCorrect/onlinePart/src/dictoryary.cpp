#include "../include/dictoryary.h"
#include "../include/configuration.h"
#include "../include/macro.h"

#include <iostream>
#include <fstream>
#include <sstream>

namespace wd
{

Dictionary* Dictionary::_pDict = nullptr;
//Dictionary* Dictionary::_pDict = Dictionary::getInstance();

Dictionary::AutoRelease Dictionary::_auto;

Dictionary::AutoRelease::AutoRelease() { cout << "AutoRelease()" << endl; }

Dictionary::AutoRelease::~AutoRelease() 
{
    if (nullptr != _pDict) {
        delete _pDict;
    }
    cout << "~AutoRelease()" << endl;
}

Dictionary::Dictionary()
{
    auto configMap = Configuration::getInstance()->_configMap;
    auto retIter = configMap.find(DICT_STORE_PATH);
    string dictPath = retIter->second;
    
    ifstream ifs;
    ifs.open(dictPath, ios::in);
    if (ifs.fail()) { ERROR_EXIT("open dictionary"); }

    string line;
    while (getline(ifs, line)) {
        istringstream iss(line);
        pair<string, size_t> newPair;
        iss >> newPair.first;
        iss >> newPair.second;

        _dictVec.push_back(newPair);
    }
    ifs.close();
    
    retIter = configMap.find(INDEX_FILES_PATH);
    string indexPath = retIter->second;
    ifs.open(indexPath, ios::in);
    if (ifs.fail()) { ERROR_EXIT("open index"); }

    string().swap(line);
    while(getline(ifs, line)) {
        istringstream iss(line);
        pair<string, set<size_t>> newPair;
        iss >> newPair.first;

        size_t lineNo;
        while (iss >> lineNo) {
            newPair.second.insert(lineNo);
        }
        _indexUnorderMap.insert(newPair);
    }
}

Dictionary::~Dictionary() { cout << "~Dictionary()" << endl; }

const vector<pair<string, size_t>>& Dictionary::dictVecGet() const 
{ return _dictVec; }

const unordered_map<string, set<size_t>>& Dictionary::indexUnorderMapGet() const
{ return _indexUnorderMap; }

}
