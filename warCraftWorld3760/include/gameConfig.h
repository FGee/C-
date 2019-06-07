#ifndef _GAME_CONFIG_H__
#define _GAME_CONFIG_H__
#include "world.h"

using namespace warcraft;

namespace warcraft
{

class GameConfig
{
public:
    class AutoRelease
    {
    public:
        ~AutoRelease()
        {
            if (_pConfig != nullptr) {
                delete _pConfig;
            }
        }
    };
    static GameConfig* getInstance()
    {
        if (nullptr == _pConfig) {
            _pConfig = new GameConfig();
            (void)_auto;
        }
        return _pConfig;
    }
public:
    void loadConfigFile(const char* fileName);
    void start();
private:
    size_t _group;
    size_t _cityNum;
    size_t _redElement;
    size_t _blueElement;
    vector<Warrior_t> _redOrder;
    vector<Warrior_t> _blueOrder;
    vector<size_t> _redInitLife;
    vector<size_t> _blueInitLife;
private:
    static GameConfig* _pConfig;
    static AutoRelease _auto;
};

}

#endif

