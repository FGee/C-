#include "../include/cppJiebaSplitTool.h"

namespace wd
{

CppJiebaSplitTool::CppJiebaSplitTool()
: SplitTool(), _jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH,
         IDF_PATH, STOP_WORD_PATH) {}

vector<string> CppJiebaSplitTool::cut(const string& sentence)
{
    vector<string> words;
    _jieba.Cut(sentence, words, true);
    return words;
}

CppJiebaSplitTool::~CppJiebaSplitTool()
{
    cout << "~CppJiebaSplitTool()" << endl;
}

}
