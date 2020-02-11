#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
// #include <limit>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        const int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int delta = 1; delta < len; delta += 2) {
            for(int j = 0; j + delta < len; j++) {
                if (delta == 1 && s[j] == '(' && s[j+1] == ')') {
                    dp[j][j+1] = true;
                    res = max(res, 2);
                }
                else {
                    if (dp[j+1][j+delta-1] && s[j] == '(' && s[j+delta] == ')') {
                        res = max(res, delta+1);
                        dp[j][j + delta] = true;
                        continue;
                    }
                    for(int i = j + 1; i < j + delta - 1; i++) {
                        if (dp[j][i] && dp[i+1][j+delta]) {
                            dp[j][j + delta] = true;
                            res = max(res, delta+1);
                            break;        
                        }
                    }
                    
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // cout << s.longestValidParentheses("(((((()())()()))()(()))") << endl;
    cout << s.longestValidParentheses("(()") << endl;
    return 0;
}
