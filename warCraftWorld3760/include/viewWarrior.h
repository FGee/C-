#ifndef __WARRIOR_VIEW_H__
#define __WARRIOR_VIEW_H__
#include "type.h"
#include "time.h"
#include "warrior.h"

#include <sstream>

using namespace warcraft;

namespace warcraft
{

class WarriorView
{
public:
    void warriorSet(Warrior* w) { _warrior = w; }
    void born()
    {
        cout << Time::getInstance()->showTime() << " "
            << name() << " born" << endl;
    }
    void march()
    {
        cout << Time::getInstance()->showTime() << " "
            << name() << " marched to city " << _warrior->posGet()
            << " with " << _warrior->hpGet() << " elements and force "
            << _warrior->apGet() << endl;
    }
    void beKilled()
    {
        cout << Time::getInstance()->showTime() << " " << name()
            << " was killed in " << _warrior->posGet() << endl;
    }
    void yelled()
    {
        cout << Time::getInstance()->showTime() << " " << name()
            << " yelled in " << _warrior->posGet() << endl;
    }
    void earned(size_t eleEarn)
    {
        cout << Time::getInstance()->showTime() << " " << name()
            << " earned " << eleEarn 
            << " elements for his headquarter" << endl;
    }
    void reached()
    {
        cout << Time::getInstance()->showTime() << " " << name()
            << "reached " << enum2strColor((RED == _warrior->colorGet()) ? BLUE : RED)
            << " headquarter with " << _warrior->hpGet() 
            << " and force " << _warrior->apGet() << endl;
    }
private:
    string name()
    {
        std::ostringstream oss;
        oss << enum2strColor(_warrior->colorGet())
            << " " << enum2strWarrior(_warrior->typeGet())
            << " " << _warrior->idGet();
        return oss.str();
    }
private:
    Warrior* _warrior;
};

}

#endif

