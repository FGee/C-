#ifndef __HEADQUARTER_H__
#define __HEADQUARTER_H__
#include "type.h"
#include "warrior.h"
#include "viewWarrior.h"

#include <memory>
#include <map>
#include <vector>

using namespace warcraft;
using namespace std;

namespace warcraft
{

class Headquarter
{
    friend class World;
    friend class HeadquarterView;
public:
    Headquarter(Color_t c) : _color(c), _element(0),
    _nextWarriorId(0), _spWarriors(new vector<Warrior*>()), 
    _warriorsNums(5, 0), _enemyNum(0), 
    _rewardElement(8) {}
    //void createOrderSet(const vector<Warrior_t>& newOrder) { _createOrder = newOrder; }
    //void initHpSet(vector<size_t>& newHp) { _initHp = newHp; }
    //void initApSet(vector<size_t>& newAp) { _initAp = newAp; }
    void increaseElement(size_t incre) { _element += incre; }
    void idIncrease() { ++_nextWarriorId; }
    Color_t colorGet() const { return _color; }
    void createWarrior(size_t cityNum);
    shared_ptr<Warrior> newWarriorByType(Warrior_t warrior, size_t cityNum);
    void warriorDecrese(Warrior_t warrior) { --_warriorsNums[warrior];  }

    void addEnemy() { ++_enemyNum; }
    size_t rewardWinner()
    {
        if (_element >= _rewardElement) {
            _element -= _rewardElement;
            return _rewardElement;
        } else 
            return 0;
    }
private:
    Color_t _color;
    size_t _element;
    vector<Warrior_t> _createOrder;
    vector<size_t> _initHp;
    vector<size_t> _initAp;
    
    size_t _nextWarriorId;
    shared_ptr<vector<Warrior*>> _spWarriors;
    vector<size_t> _warriorsNums;

    size_t _enemyNum;
    size_t _rewardElement;
private:
    WarriorView _warriorView;
};

}

#endif

