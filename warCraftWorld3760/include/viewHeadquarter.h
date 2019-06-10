#ifndef __HEADQUARTER_VIEW_H__
#define __HEADQUARTER_VIEW_H__
#include "type.h"
#include "time.h"
#include "headquarter.h"

using namespace warcraft;

namespace warcraft
{

class HeadquarterView
{
public:
    void headquarterSet(Headquarter* h) { _headquarter = h; }
    void beTaken()
    {
        cout << Time::getInstance()->showTime() << " "
            << enum2strColor(_headquarter->_color) << " headquarter was taken"
            << endl;
    }
    void reportElements()
    {
        cout << Time::getInstance()->showTime() << " "
            << _headquarter->_element << " elements in "
            << enum2strColor(_headquarter->_color)
            << " headquarter" << endl;
    }
private:
    Headquarter* _headquarter;
};

}

#endif

