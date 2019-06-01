#include "dictionary.h" 

void Dictionary::read(const std::string & fileName)
{
    ifstream ifs;
    ifs.open(fileName, ifstream::in);
    if (ifs.fail()) {
        cout << ">> ifstream open file error!" << endl;
        return ;
    }
    string tempWrd;
    while (ifs >> tempWrd) {
        if (is_number(tempWrd)) {
            continue;
        }
        put_into_word_list(tempWrd);
    }
    ifs.close();
}

bool Dictionary::is_number(const string& tempWrd) const
{
    if (isdigit((tempWrd.c_str())[0])) {
        return true;
    } else {
        return false;
    }
}

void Dictionary::put_into_word_list(const string& tempWrd)
{
    auto begIter = _wordDir.begin();
    auto endIter = _wordDir.end();
    while (begIter != endIter) {
        if (begIter->first == tempWrd) {
            ++begIter->second;
            return;
        }
        ++begIter;
    }
    _wordDir.push_back(std::make_pair(tempWrd, 1));
}

bool cmp_bigger(const std::pair<string, int> & lhs, const std::pair<string, int> & rhs) 
{
    return lhs.second > rhs.second;
}

void Dictionary::sort_word_dir()
{
    sort(_wordDir.begin(), _wordDir.end(), cmp_bigger);
}

void Dictionary::store(const std::string & fileName)
{
    ofstream ofs;
    ofs.open(fileName, ofstream::out);
    for (auto & elem : _wordDir) {
        ofs << elem.first << "\t" << elem.second << endl;
    }
    ofs.close();
}
