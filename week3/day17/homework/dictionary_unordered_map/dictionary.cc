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
    auto retIter = _wordDir.find(tempWrd);
    if (retIter != _wordDir.end()) {
        ++retIter->second;
        return;
    }
    _wordDir.insert(std::make_pair(tempWrd, 1));
}

bool cmp_bigger(const std::pair<string, int> & lhs, const std::pair<string, int> & rhs) 
{
    return lhs.second > rhs.second;
}

void Dictionary::map2vector()
{
    for (auto & e : _wordDir) {
        _wordDirToSort.push_back(std::pair<string, int>(e.first, e.second));
    }
}

void Dictionary::sort_word_dir()
{
    map2vector();
    sort(_wordDirToSort.begin(), _wordDirToSort.end(), cmp_bigger);
}

void Dictionary::store(const std::string & fileName)
{
    ofstream ofs;
    ofs.open(fileName, ofstream::out);
    for (auto & elem : _wordDirToSort) {
        ofs << elem.first << "\t" << elem.second << endl;
    }
    ofs.close();
}
