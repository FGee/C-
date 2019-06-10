#ifndef __TIME_H__
#define __TIME_H__
#include "type.h"

using namespace warcraft;

namespace warcraft
{

class Time 
{
public:
    class AutoRelease
    {
    public:
        ~AutoRelease()
        {
            if (_pTime != nullptr) {
                delete _pTime;
            }
        }
    };

    static Time* getInstance()
    {
        if (nullptr == _pTime) {
            _pTime = new Time;
            (void)_auto;
        }
        return _pTime;
    }

    size_t hourGet() { return _hour; }
    size_t minuteGet() { return _minute; }

    void increase()
    {
        if (50 == _minute) {
            _hour += 1;
            _minute = 0;
        } else {
            _minute += 10;
        }
    }

    std::string showTime() 
    {
        char buf[10] = { 0 };
        sprintf(buf, "%03ld:%02ld", _hour, _minute);
        return buf;
    }
private:
    Time() : _hour(0), _minute(0) {}
    ~Time() {}
private:
    static Time* _pTime;
    size_t _hour;
    size_t _minute;
    static AutoRelease _auto;
};

//Time* Time::_pTime = nullptr;

}

#endif

