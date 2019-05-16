#include "dictionary.h" 

Dictionary::~Dictionary()
{
    for (int i = 0; i < MAXKEY; ++i) {
        if (nullptr != _pArr[i]) {
            delete _pArr[i];
        }
    }
    delete [] _pArr;
}

void Dictionary::read(const std::string & fileName)
{
    ifstream ifs;
    ifs.open(fileName, ifstream::in);
    if (ifs.fail()) {
        cout << ">> ifstream open file error!" << endl;
        return ;
    }
    string line;
    while (std::getline(ifs, line)) {
        _file.push_back(line);
    }
    ifs.close();
}

void Dictionary::line_handle()
{
    for (string & r_line : _file) {
        istringstream iss(r_line);
        string word;
        while (iss >> word) {
            int hash = elf_hash(word.c_str());
            if (nullptr == _pArr[hash]) {
                _pArr[hash] = new WordInfo_t();
                strcpy(_pArr[hash]->word, word.c_str());
            }
            ++_pArr[hash]->num;
        }
    }
}

int Dictionary::elf_hash(const char *key)//哈希公式
{
	int h = 0, g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
			h ^= g >> 24;
		h &= ~g;
	}
	return h % MAXKEY;
}

void Dictionary::store(const std::string & fileName)
{
    ofstream ofs;
    ofs.open(fileName, ofstream::out);
    for (int i = 0; i < MAXKEY; ++i) {
        if (nullptr != _pArr[i]) {
            ofs << _pArr[i]->word << "\t" << _pArr[i]->num << endl; 
        }
    }
    ofs.close();
}
