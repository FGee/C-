#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string.h>

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using std::ifstream;
using std::ofstream;

using std::string;
using std::vector;

using std::cin;
using std::cout;
using std::endl;

class Dictionary
{
public:
    void read(const std::string & filename);
    void map2vector();
    void sort_word_dir();
    void store(const std::string & filename);
private:
    void put_into_word_list(const string&);
    bool is_number(const string&) const;
private:
    vector<std::pair<string, int>> _wordDirToSort;
    std::unordered_map<string, int> _wordDir;
};

#endif
