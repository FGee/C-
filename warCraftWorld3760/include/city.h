#ifndef __CITY_H__
#define __CITY_H__
#include "type.h"

namespace warcraft
{

class City
{
public:
    City(size_t id, size_t incre = 8, size_t life = 8)
        : _id(id), _color(NONE), _increase(incre), _lifeElement(life) {}
    size_t idGet() const { return _id; }
    size_t colorGet() const { return _color; }
    size_t elementGet() const { return _lifeElement; }

    void colorSet(Color_t color) { _color = color; }
    void lifeElementClear() { _lifeElement = 0; }

    void produceElement() { _lifeElement += _increase; }
private:
    size_t _id;
    Color_t _color;
    size_t _increase;
    size_t _lifeElement;
};

}

#endif

