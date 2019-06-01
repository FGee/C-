#include "text_query.h"

#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;

void TextQuery::readFile(const char* fileName)
{
    std::ifstream ifs;
    ifs.open(fileName, std::istream::in);
    if (ifs.fail()) {
        cout << ">> open the file fail <<" << endl;
        return;
    }
    string tmpLine;
    int line_cnt = 0;
    while (std::getline(ifs, tmpLine)) {
        _lines.push_back(tmpLine);
        line_produce(tmpLine, line_cnt);
        ++line_cnt;
    }
}

void TextQuery::wrd_to_lower(string & tmpWrd)
{
    for (auto & e : tmpWrd) {
        e = tolower(e);
    }
}

void TextQuery::line_produce(const string & line, const int& line_cnt)
{
    std::stringstream ss(line);
    string tmpWord;
    while (ss >> tmpWord) {
        wrd_to_lower(tmpWord);
        auto iterFind = _word2Line.find(tmpWord);
        if (iterFind == _word2Line.end()) {
            std::pair<string, set<int>> tmpPair;
            tmpPair.first = tmpWord;
            tmpPair.second.insert(line_cnt);
            auto retPair = _word2Line.insert(tmpPair);
            if (!retPair.second) {
                cout << ">> insert fail <<" << endl;
                return;
            }
        } else {
            iterFind->second.insert(line_cnt);
        }
        ++_dict[tmpWord];
    }
}

void TextQuery::query(const string& wrd_query)
{
    cout << "-------------------------------------" << endl;
    auto retIter = _word2Line.find(wrd_query);
    if (retIter == _word2Line.end()) {
        cout << "The word is not exist" << endl;
        return;
    } else {
        cout << wrd_query << " occurs " << _dict[wrd_query] << " times" << endl;
        auto begIter = _word2Line[wrd_query].begin();
        auto endIter = _word2Line[wrd_query].end();
        while (begIter != endIter) {
            cout << "(line " << *begIter << ") " << _lines[*begIter] << endl;
            ++begIter;
        }
    }
}

