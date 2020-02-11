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

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         const int n = p.size(), m = s.size();
//         vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//         for(int i = 0; i <= n; i++) dp[i][0] = true;
        
//         if (p[0] == '.')    dp[1][1] = true;
//         else                dp[1][1] = s[0] == p[0];
        
//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j <= m; j++) {
//                 if (p[i-1] == '*') {
//                     dp[i][j] = dp[i-1][j] || p[i-2] == '.' ? true : (dp[i][j-1] && p[i-2] == s[j-1]);    
//                 } else  {
//                     dp[i][j] = dp[i-1][j] || dp[i-1][j-1] && (p[i-1] == '.' ? true : p[i-1] == s[j-1]);
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        // 第0行 eg s = "" p1 = "a*a*b*" true p2 = "a*a" false
        for(int i = 1; i <= m; i++) {
            dp[0][i] = p[i-1] == '*' ? dp[0][i-2] : dp[0][i];
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*') {
                    if (p[j-2] == s[i-1] || p[j-2] == '.') 
                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                    else if (p[j-2] != s[i-1]){
                        dp[i][j] = dp[i][j-2];
                    }
                }
            }
        }
        return dp[n][m];
    }
};

int main(int argc, char const *argv[])
{
    // "mississippi"
    // "mis*is*ip*."

    Solution s;
    // string a = "mississippi";
    // string b = "mis*is*ip*.";

    // string a = "aaa";
    // string b = "ab*a*c*a";

    string a = "ab";
    string b = ".*";
    cout << s.isMatch(a, b) << endl;
    return 0;
}
