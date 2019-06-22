#pragma once

#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

namespace wd
{

class Dictionary
{
    class AutoRelease
    {
    public:
        AutoRelease();
        ~AutoRelease();
    };
public:
    vector<pair<string, size_t>> _dictVec;
    unordered_map<string, set<size_t>> _indexUnorderMap;

    const vector<pair<string, size_t>>& dictVecGet() const;
    const unordered_map<string, set<size_t>>& indexUnorderMapGet() const;
public:
    static Dictionary* getInstance()
    {
        if (nullptr == _pDict) {
            _pDict = new Dictionary();
        }
        return _pDict;
    }
private:
    Dictionary();
    ~Dictionary();

    static Dictionary* _pDict;
    static AutoRelease _auto;
};

}
