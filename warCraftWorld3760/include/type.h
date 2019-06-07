#ifndef __TYPE_H__
#define __TYPE_H__
#include <iostream>

namespace warcraft
{

using size_t = std::size_t;

enum Color_t {
    NONE,
    RED,
    BLUE
};

enum Warrior_t {
    DRAGON,
    NINJA,
    ICEMAN,
    LION,
    WORF
};

}

#endif

