#pragma once

#include <string>
#include <map>
#include <set>
#include <memory>
#include <vector>

using namespace std;

namespace wd
{

class IndexProducer
{
public:
    void produceIndex();
private:
    void loadDict();
    int readNBytes(const char* ch);
    void storeIndexFile();
    
    map<string, set<size_t>> _indexMap;
    vector<pair<string, size_t>> _dictVec;
};

}
