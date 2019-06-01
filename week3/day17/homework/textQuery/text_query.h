#ifndef __TEXT_QUERY_H__
#define __TEXT_QUERY_H__
//#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using std::string;
using std::vector;
//using std::unordered_map;
using std::map;
using std::set;

class TextQuery
{
public:
    void readFile(const char*);
    void query(const string & word);
private:
    void wrd_to_lower(string & tmpWrd);
    void line_produce(const string & line, const int & line_cnt);
private:
    vector<string> _lines;
    //map<int, string> _lines;
    //unordered_map<int, string> _lines;
    map<string, set<int>> _word2Line;
    map<string, int> _dict;
};

#endif

