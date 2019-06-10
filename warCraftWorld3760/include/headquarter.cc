#include "headquarter.h"

void Headquarter::createWarrior(size_t cityNum)
{
    Warrior_t warrior = _createOrder[_nextWarriorId % 5];
    if (_element < _initHp[warrior]) { return; } // 生命元不够，不生产
    _spWarriors->push_back(newWarriorByType(warrior, cityNum).get());

    _warriorView.warriorSet((*_spWarriors)[_nextWarriorId]);
    _warriorView.born();

    ++_nextWarriorId;
    ++_warriorsNums[warrior];
    _element -= _initHp[warrior];
}

shared_ptr<Warrior> Headquarter::newWarriorByType(Warrior_t warrior, size_t cityNum)
{
    switch (warrior) {
        case DRAGON:
            return shared_ptr<Warrior>((Warrior*)new Dragon(
                                                    _color, warrior, 
                                                    _nextWarriorId, 
                                                    _initHp[DRAGON], 
                                                    _initAp[DRAGON], 
                                                    cityNum));
        case NINJA:
            return shared_ptr<Warrior>((Warrior*)new Ninja(
                                                    _color, warrior, 
                                                    _nextWarriorId, 
                                                    _initHp[NINJA], 
                                                    _initAp[NINJA], 
                                                    cityNum));
        case ICEMAN:
            return shared_ptr<Warrior>((Warrior*)new Iceman(
                                                    _color, warrior, 
                                                    _nextWarriorId, 
                                                    _initHp[ICEMAN], 
                                                    _initAp[ICEMAN], 
                                                    cityNum));
        case LION:
            return shared_ptr<Warrior>((Warrior*)new Lion(
                                                    _color, warrior, 
                                                    _nextWarriorId, 
                                                    _initHp[LION], 
                                                    _initAp[LION], 
                                                    cityNum));
        case WORF:
            return shared_ptr<Warrior>((Warrior*)new Wolf(
                                                    _color, warrior, 
                                                    _nextWarriorId, 
                                                    _initHp[WORF], 
                                                    _initAp[WORF],
                                                    cityNum));
    }
}
