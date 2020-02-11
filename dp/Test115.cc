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
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size(), vector<int>(s.size() + 1, 0));
        for(int i = 0; i < t.size(); i++) {
            if (i == 0) {
                for(int j = 1; j <= s.size(); j++) {
                    dp[i][j] = dp[i][j-1];
                    if (t[0] == s[j-1]) { 
                        dp[i][j] ++;
                    }
                }
            } else {
                for(int j = 1; j <= s.size(); j++) {
                    dp[i][j] = dp[i][j-1];
                    if (t[i] == s[j-1]) {
                        dp[i][j] += dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[t.size()][s.size()];
    }
};

int main(int argc, char const *argv[])
{
    string S = "rabbbit", T = "rabbit";
    Solution s;
    cout << s.numDistinct(S, T) << endl;
    return 0;
}
