#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        for (auto & ch : s) {
            if (!isAntiBracket(ch)) {
                _brackets.push(ch);
            } else {
                if (_brackets.empty()) {
                    return false;
                }
                if (isMatch(_brackets.top(), ch)) {
                    _brackets.pop();
                } else {
                    return false;
                }
            }
        }
        if (_brackets.empty()) {
            return true;
        } else {
            return false;
        }
    }

    bool isAntiBracket(const char& ch) {
        switch (ch) {
        case '}': case ']': case ')':
            return true;
        default:
            return false;
        }
    }

    bool isMatch(const char& lch, const char& rch)
    {
        if (('{' == lch && '}' == rch)
            || ('[' == lch && ']' == rch)
            || ('(' == lch && ')' == rch)) {
            return true;
        } else {
            return false;
        }
    }
private:
    stack<char> _brackets;
};

int main(int argc, char ** argv)
{
    Solution sol;
    cout << "ret = " << sol.isValid(argv[1]) << endl;


    return 0;
}

