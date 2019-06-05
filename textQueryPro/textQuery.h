#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

inline
string make_plural(size_t ctr, const string word, const string ending) 
{
    return ctr ? (word + ending) : word;
}

class QueryResult;
class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream& infile);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> _spFile;
    map<string, shared_ptr<set<line_no>>> _spWordMap;
};

TextQuery::TextQuery(ifstream& infile) : _spFile(new vector<string>())
{
    string line;
    while (getline(infile, line)) {
        _spFile->push_back(line);
        istringstream iss(line);
        line_no ln = _spFile->size() - 1;
        string word;
        while (iss >> word) {
            auto& spSet = _spWordMap[word];
            if (!spSet) {
                spSet.reset(new set<line_no>());
            }
            spSet->insert(ln);
        }
    }
}

class QueryResult
{
    friend ostream& operator<<(ostream& os, const QueryResult& result);
public:
    using line_no = TextQuery::line_no;
public:
    QueryResult(const string s, shared_ptr<vector<string>> f, shared_ptr<set<line_no>> l) 
        : _sought(s), _spFile(f), _spLine(l) {}
    set<line_no>::iterator begin() { return _spLine->begin(); }
    set<line_no>::iterator end() { return _spLine->end(); }
    shared_ptr<vector<string>> get_file() { return _spFile; }
private:
    string _sought;
    shared_ptr<vector<string>> _spFile;
    shared_ptr<set<line_no>> _spLine;
};

QueryResult TextQuery::query(const string& wordQuery) const
{
    static shared_ptr<set<line_no>> spEmptySet(new set<line_no>());
    auto retIter = _spWordMap.find(wordQuery);
    if (_spWordMap.end() == retIter) {
        return QueryResult(wordQuery, _spFile, spEmptySet);
    } else {
        return QueryResult(wordQuery, _spFile, retIter->second);
    }
}

ostream& operator<<(ostream& os, const QueryResult& rQr)
{
    os << rQr._sought << " occurs " << rQr._spLine->size()
        << " " << make_plural(rQr._spLine->size(), "time", "s") << endl;

    for (auto & e : *rQr._spLine) {
        cout << "\tline(" << e + 1 << ") " << (*rQr._spFile)[e] << endl;
    }

    return os;
}

