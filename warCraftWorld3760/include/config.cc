#include "config.h"

using namespace warcraft;

Config* Config::_pConfig = nullptr;

void Config::loadConfig(istream& is)
{
    string line;
    getline(is, line);
    istringstream iss(line);
    iss >>_testGroups;

    for (size_t caseNo = 0; caseNo < _testGroups; ++caseNo) {
        getline(is, line);
        istringstream iss(line);
        string wrd;
        iss >> wrd; // 初始生命元
        _initElement.push_back(vector<size_t>(2, atol(wrd.c_str()))); 

        iss >> wrd; // 城市数目
        _cityNum.push_back(atol(wrd.c_str())); 

        iss >> wrd; // 事件输出时间限制
        _tLimit.push_back(atol(wrd.c_str())); 

        vector<Warrior_t> createOrderRed{ ICEMAN, LION, WORF, NINJA, DRAGON }; // 武士创建顺序设定
        vector<Warrior_t> createOrderBlue{ LION, DRAGON, NINJA, ICEMAN, WORF }; // 武士创建顺序设定
        vector<vector<Warrior_t>> createOrder{ createOrderRed, createOrderBlue };
        _warriorCreateOrder.push_back(createOrder);

        getline(is, line); // 武士初始生命值设定
        istringstream iss1(line);
        vector<size_t> initHp;
        while (iss1 >> wrd) {
            initHp.push_back(atol(wrd.c_str()));
        }
        _warriorInitHp.push_back(vector<vector<size_t>>(2, initHp));

        getline(is, line); // 武士初始攻击力设定
        istringstream iss2(line);
        vector<size_t> initAp;
        while (iss2 >> wrd) {
            initAp.push_back(atol(wrd.c_str()));
        }
        _warriorInitAp.push_back(vector<vector<size_t>>(2, initAp));
    }
}

void Config::startTest()
{
    for (; _caseNo < _testGroups; ++_caseNo) {
        cout << "Case:" << _caseNo + 1 << endl;;
        World wrld;
        wrld.initWorld();
        wrld.startWar();
    }
}

void Config::printConfig()
{
    cout << "testGroup: " << _testGroups << endl;
    for (; _caseNo < _testGroups; ++_caseNo) {
        cout << "Case:" << _caseNo + 1 << endl;;

        cout << "initEle:" << _initElement[_caseNo][RED] << " " << _initElement[_caseNo][BLUE]
            << " cityNum:" << _cityNum[_caseNo]
            << " timeLimit:" << _tLimit[_caseNo]
            << endl;

        cout << "RED: ";
        for (auto & e: _warriorCreateOrder[_caseNo][RED]) {
            cout << e << " ";
        }
        cout << "BLUE: ";
        for (auto & e: _warriorCreateOrder[_caseNo][BLUE]) {
            cout << e << " ";
        }
        cout << endl;

        cout << "RED: ";
        for (auto & e: _warriorInitHp[_caseNo][RED]) {
            cout << e << " ";
        }
        cout << "BLUE: ";
        for (auto & e: _warriorInitHp[_caseNo][BLUE]) {
            cout << e << " ";
        }
        cout << endl;

        cout << "RED: ";
        for (auto & e: _warriorInitAp[_caseNo][RED]) {
            cout << e << " ";
        }
        cout << "BLUE: ";
        for (auto & e: _warriorInitAp[_caseNo][BLUE]) {
            cout << e << " ";
        }
        cout << endl;
    }
}
