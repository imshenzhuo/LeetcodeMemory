#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <unordered_map>
using namespace std;

class Solution {
    bool palindrom(string &s, int start, int end) {
        while(start < end) {
            if (s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }
    
    void backtrace(vector<vector<string>>& res, vector<string>& cur, string& s, int start) {
        if (start == s.size())  {
            res.push_back(cur);
            return;
        }
        for(int i = start; i < s.size(); i++) {
            if (palindrom(s, start, i)) {
                cur.push_back(s.substr(start, i - start + 1));
                backtrace(res, cur, s, i + 1);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        backtrace(res, cur, s, 0);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto ret = s.partition("aab");
    cout << ret.size() << endl;
    return 0;
}
