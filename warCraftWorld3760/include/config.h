#ifndef __CONFIG_H__
#define __CONFIG_H__
#include "type.h"
#include "world.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace warcraft;

namespace warcraft
{

class Config
{
public:
    class AutoRelease
    {
    public:
        ~AutoRelease()
        {
            if (_pConfig != nullptr) {
                delete _pConfig;
            }
        }
    };
    static Config* getInstance()
    {
        if (nullptr == _pConfig) {
            _pConfig = new Config();
            (void)_auto;
        }
        return _pConfig;
    }
public:
    void loadFromIstream(istream& is) { loadConfig(is); }
    void loadFromIfstream(ifstream& ifs) { loadConfig(ifs); }
    void loadFromIstringstream(istringstream& iss) { loadConfig(iss); }
    void loadConfig(istream& is);
    void startTest();
    void printConfig();
public:
    const vector<size_t>& initElementGet() const { return _initElement[_caseNo]; }
    size_t cityNumGet() const { return _cityNum[_caseNo]; }
    size_t tLimitGet() const { return _tLimit[_caseNo]; }
    const vector<vector<Warrior_t>>& warriorCreateOrderGet() const { return _warriorCreateOrder[_caseNo]; }
    const vector<vector<size_t>>& warriorInitHpGet() const { return _warriorInitHp[_caseNo]; }
    const vector<vector<size_t>>& warriorInitApGet() const { return _warriorInitAp[_caseNo]; }
private:
    size_t _testGroups;
    size_t _caseNo;
private:
    vector<vector<size_t>> _initElement;
    vector<size_t> _cityNum;
    vector<size_t> _tLimit;
    vector<vector<vector<Warrior_t>>> _warriorCreateOrder;
    vector<vector<vector<size_t>>> _warriorInitHp;
    vector<vector<vector<size_t>>> _warriorInitAp;
private:
    static Config* _pConfig;
    static AutoRelease _auto;
    Config() : _caseNo(0) {} 
};

}

#endif

