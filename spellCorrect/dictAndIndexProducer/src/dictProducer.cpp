#include "../include/dictProducer.h"
#include "../include/macro.h"
#include "../include/configuration.h"
#include "../include/splitTool.h"

#include <string.h>

using namespace std;

namespace wd
{

//inline // 内联函数的定义和声明必须放置再同一文件里，这时由于对编译器的可见性
DictProducer::DictProducer() 
: _engOrCn(true), _pSplitTool(nullptr) {}

//inline
DictProducer::DictProducer(SplitTool* s)
: _engOrCn(false), _pSplitTool(s) {}

void DictProducer::start()
{
    //if (_engOrCn) {
        search_raw_files_path(ENG_RAW_FILES_PATH); // 加载英文语料文件
    //} else {
        search_raw_files_path(CN_RAW_FILES_PATH); // 加载中文语料文件
    //}
    store_dict();
}

void DictProducer::search_raw_files_path(string rawFilesPath) // 可以一次加载多个语料文件
{
    shared_ptr<multimap<string, string>> spConfigMultimap = Configuration::getInstance()->_spConfigMultimap;
    auto iterRange = spConfigMultimap->equal_range(rawFilesPath);
    auto lowerIter = iterRange.first;
    auto upperIter = iterRange.second;
    for (; lowerIter != upperIter; ++lowerIter) {
        ifstream ifs;
        ifs.open(lowerIter->second, ios::in);
        if (ifs.fail()) { ERROR_EXIT("open"); }
        if (!strcmp(rawFilesPath.c_str(), ENG_RAW_FILES_PATH)) {
            produce_eng_dict(ifs);
        } else if (!strcmp(rawFilesPath.c_str(), CN_RAW_FILES_PATH)) {
            produce_cn_dict(ifs);
        }
    }
    //store_dict();
}

void DictProducer::produce_eng_dict(ifstream& ifs)
{
    string tempWrd;
    while (ifs >> tempWrd) {
        if (is_number(tempWrd)) {
            continue;
        }
        eng_wrd_to_lower(tempWrd);
        put_into_dict(tempWrd);
    }
    ifs.close();
}

bool DictProducer::is_number(const string& tempWrd) const
{
    if (isdigit((tempWrd.c_str())[0])) {
        return true;
    } else {
        return false;
    }
}

void DictProducer::eng_wrd_to_lower(string & wrd)
{
    for (auto & e : wrd) {
        e = tolower(e);
    }
}

void DictProducer::put_into_dict(const string& tempWrd)
{
    auto retIter = _dictMap.find(tempWrd);
    if (retIter != _dictMap.end()) {
        ++retIter->second;
        return;
    }
    _dictMap.insert(std::make_pair(tempWrd, 1));
}

void DictProducer::produce_cn_dict(ifstream& ifs)
{
    string line;
    vector<string> words;
    while (getline(ifs, line)) {
        vector<string>().swap(words); // 快速清空words
        words = _pSplitTool->cut(line);
        for (auto & wrd : words) {
            put_into_dict(wrd);
        }
    }
    ifs.close();
}

void DictProducer::store_dict()
{
    auto spConfigMultimap = Configuration::getInstance()->_spConfigMultimap;
    auto retIter = spConfigMultimap->lower_bound(DICT_STORE_PATH);
    ofstream ofs;
    ofs.open(retIter->second, ios::out);
    if (ofs.fail()) { ERROR_EXIT("open"); }
    for (auto & pair : _dictMap) {
        ofs << pair.first << " " << pair.second << endl;
    }
    ofs.close();

    map<string, int>().swap(_dictMap);
}

}
