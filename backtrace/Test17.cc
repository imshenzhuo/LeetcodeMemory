#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    void backtrace(vector<string> &res, int begin, string& cur, string& digits, unordered_map<int, string>& m) {
        if (begin && begin == digits.size()) {
            res.push_back(cur);
            return;
        }
        char num = digits[begin];
        for(char ch : m[num]) {
            cur[begin] = ch;
            backtrace(res, begin + 1, cur, digits, m);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<int, string> m;
        m['1'] = "";
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        string cur = digits;
        backtrace(res, 0, cur, digits, m);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.letterCombinations("23");
    for(auto i : res)   cout << i << endl;
    return 0;
}
