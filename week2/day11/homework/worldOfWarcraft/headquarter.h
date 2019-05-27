#ifndef __HEADQUARTER_H__
#define __HEADQUARTER_H__
#include "warrior.h"

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Headquarter;

typedef void (Headquarter::*pAddFunc_t)();

int _time = 0;

class Headquarter 
{
public:
    Headquarter(int life, int dragonS, int ninjaS, 
                int icemanS, int lionS, int wolfS,
                string name)
        : _lifeElement(life),
        _serialNum(1),
        _name(name),
        _flagStart(true),
        _dragonStrength(dragonS),
        _ninjaStrength(ninjaS),
        _icemanStrength(icemanS),
        _lionStrength(lionS),
        _wolfStrength(wolfS)
    {
        _minStength = minStength();
    }

    bool produce(int i)
    {
        if (_flagStart) {
            if (_lifeElement >= _minStength) {
                (this->*_funcArr[i])();
                increaseSerial();
                return true;
            }
            char buf[5] = { 0 };
            sprintf(buf, "%03d", _time);
            cout << buf << " " << _name << " headquarter stops making warriors" << endl;
            _flagStart =  false;
        }
        return false;
    }

    int minStength()
    {
        int tempArr[5] = { _dragonStrength, _ninjaStrength, _icemanStrength,  _lionStrength, _wolfStrength};
        int min = _dragonStrength;
        for(int i = 0; i < 5; ++i) {
            if (min > tempArr[i]) {
                min = tempArr[i];
            }
        } 
        return min;
    }
    void increaseSerial() { ++_serialNum; }
    int lifeElementGet() { return _lifeElement; }
    int serialNumGet() { return _serialNum; }
    void addDragon()
    {
        if (_lifeElement < _dragonStrength) {
            return;
        }
        lifeDecrease(0);
        Dragon temp(_serialNum, _dragonStrength, _lifeElement);
        _dragon.push_back(temp);
        print("dragon", _dragonStrength, _dragon.size());
        cout << "It has a " << weapon(temp.weaponGet())
            << ", and it's morale is " << temp.moraleGet()
            << endl;
    }
    void addNinja() 
    {
        if (_lifeElement < _ninjaStrength) {
            return;
        }
        lifeDecrease(1);
        Ninja temp(_serialNum, _dragonStrength);
        _ninja.push_back(temp);
        print("ninja", _ninjaStrength, _ninja.size());
        cout << "It has a " << weapon(temp.weapon1Get())
            << " and a " << weapon(temp.weapon2Get())
            << endl;
    }
    void addIceman()
    {
        if (_lifeElement < _icemanStrength) {
            return;
        }
        lifeDecrease(2);
        Iceman temp(_serialNum, _dragonStrength);
        _iceman.push_back(temp);
        print("iceman", _icemanStrength, _iceman.size());
        cout << "It has a " << weapon(temp.weaponGet())
            << endl;
    }
    void addLion() 
    {
        if (_lifeElement < _lionStrength) {
            return;
        }
        lifeDecrease(3);
        Lion temp(_serialNum, _dragonStrength, _lifeElement);
        _lion.push_back(temp);
        print("dragon", _lionStrength, _lion.size());
        cout << "It's loyalty is " << temp.loyaltyGet()
            << endl;
    }
    void addWolf() 
    {
        if (_lifeElement < _wolfStrength) {
            return;
        }
        lifeDecrease(4);
        Wolf temp(_serialNum, _dragonStrength);
        _wolf.push_back(temp);
        print("dragon", _wolfStrength, _wolf.size());
    }
    void setOrder(int* arr)
    {
        _funcArr[arr[0]] = &Headquarter::addDragon;
        _funcArr[arr[1]] = &Headquarter::addNinja;
        _funcArr[arr[2]] = &Headquarter::addIceman;
        _funcArr[arr[3]] = &Headquarter::addLion;
        _funcArr[arr[4]] = &Headquarter::addWolf;
    }
    void print(const char* typeName, int strength, int typeNum)
    {
        char buf[5] = { 0 };
        sprintf(buf, "%03d", _time);
        cout << buf << " " 
            << _name << " " 
            << typeName << " "
            << _serialNum << " "
            << "born with strength " << strength 
            << ", " << typeNum << " " << typeName
            << " in " << _name << " headquarter" << endl; 
    }
    string weapon(int weaponNo)
    {
        switch (weaponNo) {
        case 0:
            return "sword";
        case 1:
            return "bomb";
        case 2:
            return "arrow";
        default:
            return " ";
        }
    }
    void lifeDecrease(int no) {
        switch (no) {
        case 0:
            _lifeElement -= _dragonStrength;
            break;
        case 1:
            _lifeElement -= _ninjaStrength;
            break;
        case 2:
            _lifeElement -= _icemanStrength;
            break;
        case 3:
            _lifeElement -= _lionStrength;
            break;
        case 4:
            _lifeElement -= _wolfStrength;
            break;
        }
    }
    pAddFunc_t _funcArr[5]; 
private:
    int _lifeElement;
    int _serialNum;
    string _name;
    bool _flagStart;

    vector<Dragon> _dragon;
    vector<Ninja> _ninja;
    vector<Iceman> _iceman;
    vector<Lion> _lion;
    vector<Wolf> _wolf;

    int _minStength;
    int _dragonStrength;
    int _ninjaStrength;
    int _icemanStrength;
    int _lionStrength;
    int _wolfStrength;
};

#endif
