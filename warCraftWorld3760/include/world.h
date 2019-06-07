#ifndef __WORLD_H__
#define __WORLD_H__
#include "headquarter.h"
#include "city.h"
#include "time.h"

#include <memory>

using namespace warcraft;

namespace warcraft
{

class World
{
public:
    World() 
        : _upHeadquaters(new map<Color_t, Headquarter>()),
        _upCitys(new vector<City>()) {}
    void initWorld(size_t initElement);
    void setRedCreateOrder();
    void setBlueCreateOrder();
    void startWar();
private:
    void timeline00();
    void timeline10();
    void timeline20();
    void timeline30();
    void timeline40();
    void timeline50();
private:
    unique_ptr<map<Color_t, Headquarter>> _upHeadquaters;
    unique_ptr<vector<City>> _upCitys;
};

}

#endif

