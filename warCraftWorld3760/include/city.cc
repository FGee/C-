#include "city.h"

size_t City::warriorNum()
{
    size_t warriorNum = 0;
    for (int i = 0; i < 2; ++i) {
        if (nullptr != _warriors[i]) {
            ++warriorNum;
        }
    }
    return warriorNum;
}

bool City::ifObtainElement(Color_t color)
{
    if (1 == warriorNum() && _warriors[color] != nullptr)
        return true;
    else 
        return false;
}

Color_t City::fight(Warrior* warrior_er, Warrior* warrior_ed, bool& fightBack)
{
    size_t lion_hp_before = 0;// 狮子战前的hp
    Color_t color_er = NONE; //主动攻击者的颜色
    Color_t winner_color = NONE; //胜利者的颜色

    if (RED == _color || ((NONE == _color) && (_id % 2))) {
        color_er = RED;
        if (LION == _warriors[BLUE]->typeGet()) {//如果被击者为狮子，则记录战前生命值
            lion_hp_before = _warriors[BLUE]->hpGet();
        }
        winner_color = fightProcess(RED, BLUE, fightBack);

        warrior_er = _warriors[RED]; warrior_ed = _warriors[BLUE];
    } else if (BLUE == _color || ((NONE == _color) && !(_id % 2))) {
        color_er = BLUE;
        if (LION == _warriors[RED]->typeGet()) {
            lion_hp_before = _warriors[RED]->hpGet();
        }
        winner_color = fightProcess(BLUE, RED, fightBack);
        
        warrior_er = _warriors[BLUE]; warrior_ed = _warriors[RED];
    }
    cout << "11111" << endl;
    fightResult(color_er, winner_color, lion_hp_before);
    cout << "11111" << endl;

    return winner_color;
}

Color_t City::fightProcess(Color_t attacker_col, Color_t attacked_col, bool& fightBack)
{
    _warriors[attacked_col]->hpDecrese(_warriors[attacker_col]->apGet()); //攻击

    if (_warriors[attacked_col]->hpGet() && (NINJA != _warriors[attacked_col]->typeGet())) {//被击者或者且不为Ninja
        _warriors[attacker_col]->hpDecrese(_warriors[attacked_col]->apGet() / 2); //反击
        fightBack = true;
    }

    if (_warriors[attacker_col]->hpGet() && !_warriors[attacked_col]->hpGet()) {
        return attacker_col;
    } else if (!_warriors[attacker_col]->hpGet() && _warriors[attacked_col]->hpGet()) {
        return attacked_col;
    }
    return NONE;
}

void City::fightResult(Color_t attacker_color, 
                       Color_t winner_color, size_t lion_hp_before)
{
    cout << "winner_color: " << winner_color << endl;
    cout << "win warrior: " << _warriors[winner_color] << endl;
    Warrior_t winner_warrior = _warriors[winner_color]->typeGet();
    cout << "11111" << endl;
    if (NONE == winner_color) {
        return;
    } else if (DRAGON == winner_warrior) {
        ;
    } else if (WORF == winner_warrior) {
        if (winner_color == attacker_color) {
            Wolf* tmp = (Wolf*)(_warriors[winner_color]);
            tmp->killsIncrease();
        }
    }
    cout << "11111" << endl;

    Color_t loser_color = NONE;//获取失败者的颜色
    if (RED != winner_color) {
        loser_color = RED; 
    } else {
        loser_color = BLUE;
    }

    if (LION == _warriors[loser_color]->typeGet()) {// 如果败者为lion的话，战前生命值转移至胜者
        _warriors[winner_color]->hpIncrese(lion_hp_before);
    }

    setWinner(winner_color);//city中记录本次战斗的胜者，如果与之前相同，city变色
    _warriors[loser_color] = nullptr; //败者从city中清理出去
}
