#ifndef __WARRIOR_H__
#define __WARRIOR_H__
#include "type.h"

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
protected:
    Warrior(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap)
        : _color(c), _type(wt), _id(id),
        _hp(hp), _ap(ap)
    {}
    virtual ~Warrior() = 0;
protected:
    Color_t _color;
    Warrior_t _type;
    size_t _id;
    size_t _hp;
    size_t _ap;
    int _pos;
};

class Dragon
: protected Warrior
{
public:
    Dragon(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap)
        : Warrior(c, wt, id, hp, ap)
    {}
private:
};

class Ninja
: protected Warrior
{
public:
    Ninja(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap)
        : Warrior(c, wt, id, hp, ap)
    {}
private:
};

class Iceman
: protected Warrior
{
public:
    Iceman(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap)
        : Warrior(c, wt, id, hp, ap)
    {}
private:
};

class Lion
: protected Warrior
{
public:
    Lion(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap)
        : Warrior(c, wt, id, hp, ap)
    {}
private:
};

class Wolf
: protected Warrior
{
public:
    Wolf(Color_t c, Warrior_t wt, size_t id, size_t hp, size_t ap)
        : Warrior(c, wt, id, hp, ap), _killNum(0)
    {}
    size_t killNumGet() { return _killNum; }
private:
    size_t _killNum;
};

}

#endif

