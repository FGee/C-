#include "world.h"

using namespace warcraft;

void World::initWorld(size_t initElement)
{
    _spHeadquaters->insert(make_pair(RED, Headquarter(RED, initElement)));
    _spHeadquaters->insert(make_pair(BLUE, Headquarter(BLUE, initElement)));
}

