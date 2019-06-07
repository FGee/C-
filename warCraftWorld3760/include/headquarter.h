#ifndef __HEADQUARTER_H__
#define __HEADQUARTER_H__
#include "type.h"
#include "warrior.h"

#include <memory>
#include <map>
#include <vector>

using namespace warcraft;
using namespace std;

namespace warcraft
{

class Headquarter
{
    friend class HeadquarterView;
public:
    Headquarter(Color_t c, size_t e) : _color(c), _element(e) {}
    void createOrderSet(const vector<Warrior_t>& newOrder) { _createOrder = newOrder; }
    void initHpSet(vector<size_t>& newHp) { _initHp = newHp; }
    void initApSet(vector<size_t>& newAp) { _initAp = newAp; }
    void increaseElement(size_t incre) { _element += incre; }
    void idIncrease() { ++_nextWarriorId; }
    Color_t colorGet() const { return _color; }
    void createWarrior();
    shared_ptr<Warrior> newWarriorByType(Warrior_t warrior);
    void warriorDecrese(Warrior_t warrior) { --_warriorsNums[warrior];  }
private:
    Color_t _color;
    size_t _element;
    vector<Warrior_t> _createOrder;
    vector<size_t> _initHp;
    vector<size_t> _initAp;
    size_t _nextWarriorId;
    shared_ptr<map<size_t, Warrior*>> _spWarriors;
    vector<size_t> _warriorsNums;

    size_t _enemyNum;
};

}

#endif

