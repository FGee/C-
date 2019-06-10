#ifndef __WARRIOR_H__
#define __WARRIOR_H__
#include "type.h"

#include <iostream>

using namespace std;

namespace warcraft
{

class Warrior
{
public:
    Color_t colorGet() { return _color; }
    Warrior_t typeGet() { return _type; }
    size_t idGet() const { return _id; }
    size_t hpGet() const { return _hp; }
    size_t apGet() const { return _ap; }
    int posGet() const { return _pos; }
public:
    void hpDecrese(size_t decre) { _hp = (_hp > decre) ? (_hp - decre) : 0; }
    void hpIncrese(size_t incre) { _hp += incre; }
public:
    bool ifWinnerGet() { return _ifWinner; }
    void ifWinnerSet(bool ifWin) { _ifWinner = ifWin; }
public:
    void move()
    {
        if (RED == _color) {
            ++_pos;
        } else {
            --_pos;
        }
    }
public:
    Warrior(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap, size_t cityNum)
        : _color(c), _type(wt), _id(id),
        _hp(hp), _ap(ap)
    {
        _pos = (RED == _color) ? 0 : (cityNum + 1);
    }
    virtual ~Warrior() {}
protected:
    Color_t _color;
    Warrior_t _type;
    size_t _id;
    size_t _hp;
    size_t _ap;
    size_t _pos;
    bool _ifWinner;
};

class Dragon
: protected Warrior
{
public:
    Dragon(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap, size_t cityNum)
        : Warrior(c, wt, id, hp, ap, cityNum)
    {}
    ~Dragon() {}
private:
};

class Ninja
: protected Warrior
{
public:
    Ninja(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap, size_t cityNum)
        : Warrior(c, wt, id, hp, ap, cityNum)
    {}
    ~Ninja() {}
private:
};

class Iceman
: protected Warrior
{
public:
    Iceman(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap, size_t cityNum)
        : Warrior(c, wt, id, hp, ap, cityNum)
    {}
    ~Iceman() {}
    void icemanMove()
    {
        move();
        if (++_stepNum % 2) return;
        if (_hp > 9) {
            _hp -= 9;
            _ap += 20;
        } else {
            _hp = 1;
        }
    }
private:
    size_t _stepNum = 0;
};

class Lion
: protected Warrior
{
public:
    Lion(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap, size_t cityNum)
        : Warrior(c, wt, id, hp, ap, cityNum)
    {}
    ~Lion() {}
private:
};

class Wolf
: protected Warrior
{
public:
    Wolf(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap, size_t cityNum)
        : Warrior(c, wt, id, hp, ap, cityNum), _killNum(0)
    {}
    ~Wolf() {}
    void killsIncrease()
    {
        ++_killNum;
        if (!(_killNum % 2)) {
            _hp *= 2; _ap *= 2;
        }
    }
    size_t killNumGet() { return _killNum; }
private:
    size_t _killNum;
};

}

#endif

