#pragma once

#include <string>
#include <map>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

namespace wd
{

class SplitTool; 

class DictProducer
{
    using Word_t = string;
    using Frequency_t = int;
    using Index_t = string;
    using ItemNo_t = int;
public:
    DictProducer();
    DictProducer(SplitTool*);
    void start();
private:
    void search_raw_files_path(string);
    void produce_eng_dict(ifstream& ifs);
    bool is_number(const string&) const;
    void put_into_dict(const string&);
    void eng_wrd_to_lower(string&);

    void produce_cn_dict(ifstream& ifs);
    
    void store_dict();
   
    map<Word_t, Frequency_t> _dictMap;
    bool _engOrCn; // ture is eng, flase is cn
    SplitTool* _pSplitTool;
};

}
