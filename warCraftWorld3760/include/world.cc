#include "world.h"

using namespace warcraft;

void World::initWorld()
{
    buildCitys();

    _upHeadquaters.reset(new vector<Headquarter>());
    _upHeadquaters->push_back(Headquarter(RED));
    _upHeadquaters->push_back(Headquarter(BLUE));

    setElement(RED);
    setElement(BLUE);

    setCreateOrder(RED);
    setCreateOrder(BLUE);

    setWarriorHp(RED);
    setWarriorHp(BLUE);

    setWarriorAp(RED);
    setWarriorAp(BLUE);

    registerTimelineFunc();

    _duringWar = true;
}

void World::buildCitys()
{
    _upCitys.reset(new vector<City>());

    _cityNum = Config::getInstance()->cityNumGet();
    for (size_t cityId = 1; cityId <= _cityNum; ++cityId) {
        _upCitys->push_back(City(cityId));
    }
}

    inline
void World::setElement(Color_t color)
{
    Config* pConfig = Config::getInstance();
    (*_upHeadquaters)[color]._element = pConfig->initElementGet()[color]; 
}

    inline
void World::setCreateOrder(Color_t color) 
{
    Config* pConfig = Config::getInstance();
    (*_upHeadquaters)[color]._createOrder = pConfig->warriorCreateOrderGet()[color]; 
}

    inline
void World::setWarriorHp(Color_t color)
{
    Config* pConfig = Config::getInstance();
    (*_upHeadquaters)[color]._initHp = pConfig->warriorInitHpGet()[color];
}

    inline
void World::setWarriorAp(Color_t color)
{
    Config* pConfig = Config::getInstance();
    (*_upHeadquaters)[color]._initAp = pConfig->warriorInitApGet()[color];
}

void World::registerTimelineFunc()
{
    _timelineFunc[0] = bind(&World::timeline00, this);
    _timelineFunc[1] = bind(&World::timeline10, this);
    _timelineFunc[2] = bind(&World::timeline20, this);
    _timelineFunc[3] = bind(&World::timeline30, this);
    _timelineFunc[4] = bind(&World::timeline40, this);
    _timelineFunc[5] = bind(&World::timeline50, this);
}

void World::startWar()
{
    Time* pTime = Time::getInstance();
    while (_duringWar) {
        _timelineFunc[pTime->minuteGet() / 10]();
        pTime->increase();
    }
}

void World::timeline00()
{
    cout << "timeline00" << endl;
    for (auto& head : *_upHeadquaters) {
        head.createWarrior(_cityNum);
    }    
}

void World::timeline10()
{
    cout << "timeline10" << endl;
    moveFuncInvoke(RED);
    moveFuncInvoke(BLUE);
}

void World::moveFuncInvoke(Color_t color)
{
    if (RED == color) {
        auto begIter = _upCitys->begin();
        auto endIter = _upCitys->end();
        warriorMove(color, begIter, endIter);
    } else if (BLUE == color) {//对于蓝魔军而言，逆序遍历城市数组即可
        auto begIter = _upCitys->rbegin();
        auto endIter = _upCitys->rend();
        warriorMove(color, begIter, endIter);
    }
    if (2 == (*_upHeadquaters)[RED]._enemyNum) {
        _duringWar = false;
        _headquarterView.headquarterSet(&(*_upHeadquaters)[color]);
        _headquarterView.beTaken();
    } else if (2 == (*_upHeadquaters)[BLUE]._enemyNum) {
        _duringWar = false;
        _headquarterView.headquarterSet(&(*_upHeadquaters)[color]);
        _headquarterView.beTaken();
    }
}

    template <typename BegIter, typename EndIter>
void World::warriorMove(Color_t color, BegIter begIter, EndIter endIter)
{
    Headquarter& headquarter = (*_upHeadquaters)[color];
    size_t unMovedId = headquarter._nextWarriorId - 1; //刚刚生成的还在司令部的武士编号
    Warrior* unMovedWarrior = (*headquarter._spWarriors)[unMovedId]; //待前进的武士

    for (; begIter != endIter; ++begIter) { //武士向前移动一个城市
        swap(unMovedWarrior, begIter->_warriors[color]);
        if (nullptr == begIter->_warriors[color]) continue; // 空指针代表没有对应武士，在city
        if (ICEMAN == begIter->_warriors[color]->typeGet()) { //如果未iceman需注意，偶数步，减少hp，加ap
            Iceman* pTmp = (Iceman*)begIter->_warriors[color];
            pTmp->icemanMove();
            headquarter._warriorView.warriorSet((Warrior*)pTmp);
            headquarter._warriorView.march();
        } else {
            begIter->_warriors[color]->move(); // 对于非iceman，只需要将其pos值改变即可
            headquarter._warriorView.warriorSet(begIter->_warriors[color]);
            headquarter._warriorView.march();
        }
    }
    if (unMovedWarrior != nullptr) {//如果最后交换过来的不是空指针的话（武士存活），则说明以抵达敌营
        if (RED == color) {
            (*_upHeadquaters)[BLUE].addEnemy();
        } else if (BLUE == color) {
            (*_upHeadquaters)[RED].addEnemy();
        }
    }
}

void World::timeline20()
{
    cout << "timeline20" << endl;
    for (auto & city : (*_upCitys)) {
        city.produceElement();
    }
}

void World::timeline30()
{
    cout << "timeline30" << endl;
    for (auto & city : (*_upCitys)) {
        if (city.ifObtainElement(RED)) {
            size_t earned = city.elementObtain();
            (*_upHeadquaters)[RED].increaseElement(earned);
            Warrior* tmp = city._warriors[RED];
            (*_upHeadquaters)[RED]._warriorView.warriorSet(tmp);
            (*_upHeadquaters)[RED]._warriorView.earned(earned);
        } else if (city.ifObtainElement(BLUE)) {
            size_t earned = city.elementObtain();
            (*_upHeadquaters)[BLUE].increaseElement(city.elementObtain());
            Warrior* tmp = city._warriors[BLUE];
            (*_upHeadquaters)[BLUE]._warriorView.warriorSet(tmp);
            (*_upHeadquaters)[BLUE]._warriorView.earned(earned);
        }
    }
}

void World::timeline40()
{
    cout << "timeline40" << endl;
    for (auto & city : (*_upCitys)) {
        if (!city.ifFight()) { continue; } // 不够两人，不发生战斗

        Warrior* warrior_er = nullptr;
        Warrior* warrior_ed = nullptr;
        bool fightBack = false;
        Color_t winner_color = city.fight(warrior_er, warrior_ed, fightBack); // city中发生战斗
        
        _cityView.citySet(&city);
        _cityView.attack(warrior_er->colorGet(), warrior_ed->colorGet());

        if (fightBack) {
            _cityView.fightBack(warrior_ed->colorGet(), warrior_er->colorGet());
        }

        if (DRAGON == warrior_er->typeGet() 
            && (NONE == winner_color || DRAGON 
                == city._warriors[winner_color]->typeGet())) {
            Warrior* tmp = city._warriors[winner_color];
            (*_upHeadquaters)[winner_color]._warriorView.warriorSet(tmp);
            (*_upHeadquaters)[winner_color]._warriorView.yelled();
        }

        if (NONE == winner_color) { continue; }

        Color_t failer_color;
        if (winner_color == RED) {
            failer_color = BLUE;
        } else {
            failer_color = RED;
        }
        if (winner_color == warrior_er->colorGet()) {
            Warrior* tmp = city._warriors[warrior_ed->colorGet()];
            (*_upHeadquaters)[warrior_ed->typeGet()]._warriorView.warriorSet(tmp);
            (*_upHeadquaters)[warrior_ed->typeGet()]._warriorView.beKilled();
        } else {
            Warrior* tmp = city._warriors[warrior_er->colorGet()];
            (*_upHeadquaters)[warrior_er->typeGet()]._warriorView.warriorSet(tmp);
            (*_upHeadquaters)[warrior_er->typeGet()]._warriorView.beKilled();
        }
        
        if (RED == winner_color) {  //红魔据奖励胜者
            size_t reward = (*_upHeadquaters)[RED].rewardWinner();
            city._warriors[RED]->hpIncrese(reward);
        }
            
        size_t earned = city.elementObtain();
        (*_upHeadquaters)[winner_color].increaseElement(earned);
        Warrior* tmp = city._warriors[RED];
        (*_upHeadquaters)[winner_color]._warriorView.warriorSet(tmp);
        (*_upHeadquaters)[winner_color]._warriorView.earned(earned);

        if (city._raiseFlag) {
            _cityView.citySet(&city);
            _cityView.flagRaised(winner_color);
        }
    }
// 这块有待优化，可以使用模板，解决代码冗余问题，但需要多遍历一次city
    auto rbegIter = _upCitys->rbegin();
    auto rendIter = _upCitys->rend();
    for (; rbegIter != rendIter; ++rbegIter) {//蓝魔军奖励胜者
        if (!rbegIter->ifFight()) { continue; } // 没有发生过战斗的城市，不需要奖励
        if (nullptr != (*rbegIter)._warriors[BLUE]) {
            if (true == (*rbegIter)._warriors[BLUE]->ifWinnerGet()) {
            size_t reward = (*_upHeadquaters)[BLUE].rewardWinner();
            (*rbegIter)._warriors[BLUE]->hpIncrese(reward);
            }
        }
    }
}

void World::timeline50()
{
    cout << "timeline50" << endl;
    _headquarterView.headquarterSet(&(*_upHeadquaters)[RED]);
    _headquarterView.reportElements();
    _headquarterView.headquarterSet(&(*_upHeadquaters)[BLUE]);
    _headquarterView.reportElements();
}












