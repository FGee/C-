#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#define MAXKEY 2000

using std::ifstream;
using std::ofstream;

using std::stringstream;
using std::istringstream;
using std::ostringstream;

using std::string;
using std::vector;

using std::cin;
using std::cout;
using std::endl;

typedef struct {
    int num;
    char word[50];
} WordInfo_t, *pWordInfo_t;

class Dictionary
{
public:
    Dictionary() : _pArr(new pWordInfo_t[MAXKEY]()) {}
    ~Dictionary();
    void read(const std::string & filename);
    void line_handle();
    void store(const std::string & filename);
private:
    int elf_hash(const char *key);
private:
    vector<string> _file;
    pWordInfo_t *_pArr;
};

#endif
