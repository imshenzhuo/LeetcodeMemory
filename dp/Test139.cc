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
public:
   bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i = 1; i <= s.size(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j])  {
                    string word = s.substr(j,i-j);
                    if (dict.find(word)!= dict.end()) {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "leetcode";
    unordered_set<string> wordDict{"leet", "code"};
    s.wordBreak(str, wordDict);
    return 0;
}
