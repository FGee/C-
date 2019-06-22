#include "../include/indexProducer.h"
#include "../include/configuration.h"
#include "../include/macro.h"

#include <fstream>

using namespace std;

namespace wd
{

void IndexProducer::loadDict()
{
    auto spConfigMultimap = Configuration::getInstance()->_spConfigMultimap;

    auto retIter = spConfigMultimap->find(DICT_STORE_PATH);
    ifstream ifs;
    ifs.open(retIter->second, ios::in);
    if (ifs.fail()) { ERROR_EXIT("open"); }

    string line;
    while (getline(ifs, line)) {
        pair<string, size_t> newPair;
        ifs >> newPair.first;
        string frequency;
        ifs >> frequency;
        newPair.second = atol(frequency.c_str());

        _dictVec.push_back(newPair);
    }
    ifs.close();
}

void IndexProducer::produceIndex() 
{
    loadDict();
    set<string> visited;

    size_t sz = _dictVec.size();

    for (size_t lineNo = 0; lineNo < sz; ++lineNo) {
        string wrd = _dictVec[lineNo].first;
        size_t wrdSz = wrd.size();
        const char* pos = wrd.c_str();
        size_t i = 0;
        while (i < wrdSz) {
            size_t nBytes = readNBytes(wrd.c_str());
            
            string indexWrd(pos, nBytes);

            auto retIter = visited.find(indexWrd);
            visited.insert(indexWrd);
            if (retIter == visited.end()) {
                pair<string, set<size_t>> newPair;
                newPair.first = indexWrd;
                newPair.second.insert(lineNo);
                _indexMap.insert(newPair);
            }
            _indexMap[indexWrd].insert(lineNo);

            i += nBytes;
            pos += nBytes;
        }
    }
    storeIndexFile();
}

int IndexProducer::readNBytes(const char* ch)
{
    int byteNum = 1;
    int offset = 7;
    while ((*ch) & (1 << offset)) {
        --offset;
        ++byteNum;
    }

    if (byteNum > 1) {
        return byteNum - 1;
    }

    return byteNum; 
}

void IndexProducer::storeIndexFile()
{
    auto spConfigMultimap = Configuration::getInstance()->_spConfigMultimap;

    auto retIter = spConfigMultimap->find(INDEX_STORE_PATH);
    ofstream ofs;
    ofs.open(retIter->second, ios::out);
    if (ofs.fail()) { ERROR_EXIT("open"); }

    for (auto & indexItem : _indexMap) {
        ofs << indexItem.first << " ";
        for (auto & lineNoSet : indexItem.second) {
            ofs << lineNoSet << " ";
        }
        ofs << endl;
    }
    ofs.close();
}

}
