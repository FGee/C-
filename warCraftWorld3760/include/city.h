#ifndef __CITY_H__
#define __CITY_H__
#include "type.h"
#include "warrior.h"

#include <iostream>
#include <vector>

using namespace warcraft;
using namespace std;

namespace warcraft
{

class City
{
    friend class World;
    friend class CityView;
public:
    City(size_t id, size_t incre = 10, size_t life = 0)
        : _id(id), _color(NONE), _increase(incre), _element(life), _raiseFlag(false) 
    { _warriors[0] = nullptr; _warriors[1] = nullptr; }
    size_t idGet() const { return _id; }
    size_t colorGet() const { return _color; }
    size_t elementGet() const { return _element; }

    void colorSet(Color_t color) { _color = color; }
    size_t elementObtain() { size_t tmp = _element; _element = 0; return tmp; }

    void produceElement() { _element += _increase; }

    size_t warriorNum();
    bool ifObtainElement(Color_t);
    bool ifFight() { return (2 == warriorNum()) ? true : false; }

    Color_t fight(Warrior* warrior_er, Warrior* warrior_ed, bool& fightBack);

    void setWinner(Color_t winner_color)
    {
        if (_preWinner == winner_color) {
            _color = winner_color;
            _raiseFlag = true;
        }
        _preWinner = winner_color;
    }
private:
    Color_t fightProcess(Color_t, Color_t, bool&);
    void fightResult(Color_t, Color_t, size_t);
private:
    size_t _id;
    Color_t _color;
    size_t _increase;
    size_t _element;
private:
    Warrior* _warriors[2];
private:
    Color_t _preWinner;
private:
    bool _raiseFlag;
};

}

#endif

