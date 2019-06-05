#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::unordered_set;
using std::string;
using std::queue;
using std::unordered_map;
using std::swap;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> setWordList;
        for (auto & e : wordList) { // 将词典里的单词放入哈希set中
            setWordList.insert(e);
        }
        if (!setWordList.count(endWord)) { //当字典里不存在目标单词时，直接返回
            return 0;
        }   
        bool found = false;
        int level = 0;
        unordered_set<string> visited;

        auto next_state = [&](string word) {
            vector<string> result;
            auto sz = word.size();
            for (size_t i = 0; i < sz; ++i) {
                string copy(word);
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    swap(ch, copy[i]);
                    if (copy == word) {
                        continue;
                    }
                    if (setWordList.count(copy) && !visited.count(copy)) {
                        result.push_back(copy);
                        visited.insert(copy);
                    }
                    swap(ch, copy[i]);
                }    
            }
            return result;
        };

        queue<string> curState;
        queue<string> nextState;
        curState.push(beginWord);
        while (!curState.empty() && !found) {
            ++level;
            while(!curState.empty() && !found) {
                string curWord = curState.front();
                auto nextState_curWord = next_state(curWord);
                curState.pop();
                if (nextState_curWord.empty()) {
                    continue;
                }
                for (auto & e : nextState_curWord) {
                    nextState.push(e);
                    if (e == endWord) {
                        found = true;
                        break;
                    }
                }
            }
            swap(curState, nextState);
        }
        if (found) {
            return ++level;
        } else {
            return 0;
        }
    }
};

int main(void)
{
#if 1
    string start = "hit";
    string end = "cog";
    vector<string> dict{"hot", "dot", "dog", "log", "lot"};
#endif

#if 0
    string start = "hit";
    string end = "cog";
    vector<string> dict{"hot", "dot", "dog", "log", "lot", "cog"};
#endif

    Solution s;
    cout << s.ladderLength(start, end, dict) << endl;
    
    return 0;
}
