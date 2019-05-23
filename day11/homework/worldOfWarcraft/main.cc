#include "warrior.h"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Headquarter;

typedef void (Headquarter::*pAddFunc_t)();

const int _time = 0;

class Headquarter 
{
public:
    Headquarter(int life, int dragonS, int ninjaS, 
                int icemanS, int lionS, int wolfS)
        : _lifeElement(life),
        _dragonStrength(dragonS),
        _ninjaStrength(ninjaS),
        _icemanStrength(icemanS),
        _lionStrength(lionS),
        _wolfStrength(wolfS)
    {}

    int lifeElementGet() { return _lifeElement; }
    int serialNumGet() { return _serialNum; }
    void addDragon()
    {
        Dragon temp(_serialNum, _dragonStrength, _lifeElement);
        _dragon.push_back(temp);
        lifeDecrease(0);
        print("dragon", _dragonStrength, _dragon.size());
        cout << "It has a " << weapon(temp.weaponGet())
            << ", and it's morale is " << temp.moraleGet()
            << endl;
    }
    void addNinja() 
    {
        Ninja temp(_serialNum, _dragonStrength);
        _ninja.push_back(temp);
        lifeDecrease(1);
        print("ninja", _ninjaStrength, _ninja.size());
        cout << "It has a " << weapon(temp.weapon1Get())
            << " and a " << temp.weapon2Get()
            << endl;
    }
    void addIceman()
    {
        Iceman temp(_serialNum, _dragonStrength);
        _iceman.push_back(temp);
        lifeDecrease(2);
        print("iceman", _icemanStrength, _iceman.size());
        cout << "It has a " << weapon(temp.weaponGet())
            << endl;
    }
    void addLion() 
    {
        Lion temp(_serialNum, _dragonStrength, _lifeElement);
        _lion.push_back(temp);
        lifeDecrease(3);
        print("dragon", _lionStrength, _lion.size());
        cout << "It's loyalty is " << temp.loyaltyGet()
            << endl;
    }
    void addWolf() 
    {
        Wolf temp(_serialNum, _dragonStrength);
        _wolf.push_back(temp);
        lifeDecrease(4);
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
            << ", " << typeNum << "typeName"
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

    vector<Dragon> _dragon;
    vector<Ninja> _ninja;
    vector<Iceman> _iceman;
    vector<Lion> _lion;
    vector<Wolf> _wolf;

    int _dragonStrength;
    int _ninjaStrength;
    int _icemanStrength;
    int _lionStrength;
    int _wolfStrength;
};

void test()
{
    Headquarter red(20, 5, 3, 2, 3, 4);

    int arr[5] = { 0, 1, 2, 3, 4 };
    red.setOrder(arr);
    printf("%p", red._funcArr[3]);
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

