#include "type.h"

namespace warcraft
{

std::string enum2strWarrior(Warrior_t warrior)
{
    switch (warrior) {
    case DRAGON:
        return "dragon";
    case NINJA:
        return "ninja";
    case ICEMAN:
        return "iceman";
    case LION:
        return "lion";
    case WORF:
        return "worf";
    }
}

std::string enum2strColor(Color_t color)
{
    switch(color) {
    case RED:
        return "red";
    case BLUE:
        return "blue";
    case NONE:
        return "none";
    }
}

}
