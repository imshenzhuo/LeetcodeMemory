#include <cstdlib>
#include <list>
#include <cstring>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
    void backtrace(vector<string>& res, string cur, unordered_set<string>& dict, int max_len, string s, int begin) {
        if (begin == s.size()){
            res.push_back(cur.substr(0, cur.size()-1));
            return;
        }
        string sub;
        for(int i = 1; i <= max_len && i+begin-1 < s.size(); i++) {
            sub.push_back(s[i+begin-1]);
            if (dict.count(sub)) {
                backtrace(res, cur + sub + " ", dict, max_len, s, begin + i);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        int max_len = 0;
        for(int i = 0; i < wordDict.size(); i++) {
            max_len = max_len > wordDict[i].size() ? max_len : wordDict[i].size();
            dict.insert(wordDict[i]);
        }
        vector<string> res;
        backtrace(res, "", dict, max_len, s, 0);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    s.wordBreak(str, wordDict);
    return 0;
}
