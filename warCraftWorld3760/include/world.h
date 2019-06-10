#ifndef __WORLD_H__
#define __WORLD_H__
#include "headquarter.h"
#include "viewHeadquarter.h"
#include "viewCity.h"
#include "city.h"
#include "time.h"
#include "config.h"

#include <memory>
#include <functional>

using namespace warcraft;

namespace warcraft
{

class World
{
public:
    World() 
        : _upHeadquaters(new vector<Headquarter>()),
        _upCitys(new vector<City>()) {}
    void initWorld();
    void startWar();
private:
    void buildCitys();
    void setElement(Color_t color);
    void setWarriorHp(Color_t color);
    void setWarriorAp(Color_t color);
    void setCreateOrder(Color_t color);
    void registerTimelineFunc();
private:
    void timeline00();
    void timeline10();
    void timeline20();
    void timeline30();
    void timeline40();
    void timeline50();
private:
    void moveFuncInvoke(Color_t);

template <typename BegIter, typename EndIter> //这里使用了类的成员函数的模板形式，让编译器推导对应正、逆序的代码
    void warriorMove(Color_t, BegIter, EndIter);
private:
    unique_ptr<vector<Headquarter>> _upHeadquaters;
    unique_ptr<vector<City>> _upCitys;
private:
    size_t _cityNum;
private:
    function<void()> _timelineFunc[6];
    bool _duringWar;
private:
    HeadquarterView _headquarterView;
    CityView _cityView;
};

}

#endif

