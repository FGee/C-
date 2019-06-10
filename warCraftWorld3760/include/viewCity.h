#ifndef __CITY_VIEW__
#define __CITY_VIEW__
#include "city.h"
#include "time.h"
#include "warrior.h"

#include <sstream>
#include <string>

using namespace warcraft;

namespace warcraft
{

class CityView
{
public:
    void citySet(City* c) { _city = c; }
    void attack(Color_t attacker, Color_t attacked)
    {
        cout << Time::getInstance()->showTime() << " "
            << warriorInfo(attacker) << " attacked "
            << warriorInfo(attacked) << " in city "
            << _city->_id << " with " 
            << _city->_warriors[attacker]->hpGet() 
            << " elements and force "
            << _city->_warriors[attacker]->apGet() << endl;
    }
    void fightBack(Color_t attacked, Color_t attacker)
    {
        cout << Time::getInstance()->showTime() << " "
            << warriorInfo(attacked) << " fought back against "
            << warriorInfo(attacker) << " in city "
            << _city->_id << endl; 
    }
    void flagRaised(Color_t color)
    {
        cout << Time::getInstance()->showTime() << " "
            << enum2strColor(color) << " flag raised in city "
            << _city->_id << endl;
    }
private:
    std::string warriorInfo(Color_t color) 
    {
        std::ostringstream oss;
        oss << enum2strColor(color) << " " 
            << enum2strWarrior(_city->_warriors[color]->typeGet()) << " "
            << _city->_warriors[color]->idGet();
        return oss.str();
    }
    City* _city;
};

}

#endif

