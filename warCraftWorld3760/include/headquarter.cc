#include "headquarter.h"

void Headquarter::createWarrior()
{
    Warrior_t warrior = _createOrder[_nextWarriorId % 5];
    _spWarriors->insert(make_pair(_nextWarriorId, 
                                  newWarriorByType(warrior).get()));
    ++_warriorsNums[warrior];
}

shared_ptr<Warrior> Headquarter::newWarriorByType(Warrior_t warrior)
{
    switch (warrior) {
        case DRAGON:
            return make_shared<Warrior>(new Dragon(
                                                    _color, warrior, 
                                                    _nextWarriorId, 
                                                    _initHp[DRAGON], 
                                                    _initAp[DRAGON]));
        case NINJA:
            return make_shared<Warrior>(new Ninja(
                                                    _color, warrior, 
                                                    _nextWarriorId, 
                                                    _initHp[NINJA], 
                                                    _initAp[NINJA]));
        case ICEMAN:
            return make_shared<Warrior>(new Iceman(
                                                    _color, warrior, 
                                                    _nextWarriorId, 
                                                    _initHp[ICEMAN], 
                                                    _initAp[ICEMAN]));
        case LION:
            return make_shared<Warrior>(new Lion(
                                                    _color, warrior, 
                                                    _nextWarriorId, 
                                                    _initHp[LION], 
                                                    _initAp[LION]));
        case WORF:
            return make_shared<Warrior>(new Wolf(
                                                    _color, warrior, 
                                                    _nextWarriorId, 
                                                    _initHp[WORF], 
                                                    _initAp[WORF]));
    }
}
