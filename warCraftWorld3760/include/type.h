#ifndef __TYPE_H__
#define __TYPE_H__
#include <iostream>
#include <string>

namespace warcraft
{

using size_t = std::size_t;

enum Color_t {
    RED,
    BLUE,
    NONE
};

enum Warrior_t {
    DRAGON,
    NINJA,
    ICEMAN,
    LION,
    WORF
};

std::string enum2strWarrior(Warrior_t warrior);

std::string enum2strColor(Color_t color);

}

#endif

