#include "dictionary.h"

int main(int argc, char ** argv)
{
    if (3 != argc) {
        cout << "the args error" << endl;
        return -1;
    }

    Dictionary dic;
    dic.read(argv[1]);
    dic.sort_word_dir();
    dic.store(argv[2]);

    return 0;
}

