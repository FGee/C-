#pragma once
#include <string>
#include <map>
#include <memory>

#define ENG_RAW_FILES_PATH "eng_raw_files_path"
#define CN_RAW_FILES_PATH "cn_raw_files_path"
#define DICT_STORE_PATH "dict_store_path"
#define INDEX_STORE_PATH "index_store_path"

using namespace std;

namespace wd
{

class Configuration
{
    using Item = string;
    using Value = string;
    class AutoRelease
    {
    public:
        AutoRelease();
        ~AutoRelease();
    };
public:
    shared_ptr<multimap<Item, Value>> _spConfigMultimap;
    void loadConfigFile(const char* fileName);
    //shared_ptr<multimap<Item, Value>> getConfigMultimap();
private:
public:
    static Configuration* getInstance();
private:
    Configuration();
    ~Configuration();

    static Configuration* pConfiguration;
    static AutoRelease _auto;
};

}
