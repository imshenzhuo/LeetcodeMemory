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
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp (n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; i++) dp[0][i] = p[i-1] == '*' && dp[0][i-1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "adceb";
    string p = "*a*b";
    cout << s.isMatch(str, p) << endl;
    return 0;
}
