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

// class Solution {
//     bool help(string s1, int begin1, int end1, string s2, int begin2, int end2, string s3, int begin3, int end3) {
//         if (begin1 != end1 && s3[begin3] == s1[begin1] && help(s1, begin1 + 1, end1, s2, begin2, end2, s3, begin3 + 1, end3)) {
//             return true;
//         } else if (begin2 != end2 && s3[begin3 == s2[begin2]] && help(s1, begin1, end1, s2, begin2 + 1, end2, s3, begin3 + 1, end3)) {
//             return true;
//         } 
//         return false;
//     }
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         return help(s1, 0, s1.size(), s2, 0, s2.size(), s3, 0, s3.size());
//     }
// };
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        int nm = s3.size();
        if (n + m != nm)    return false;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            if(s1[i-1] == s3[i-1] && dp[i-1][0])
                dp[i][0] = 1;
            else 
                break;
        }
        for(int i = 1; i <= m; i++) {
            if(s2[i-1] == s3[i-1] && dp[0][i-1])
                dp[0][i] = 1;
            else 
                break;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if( (s3[i+j-1] == s2[j-1] && dp[i][j-1]) || (dp[i-1][j] && s3[i+j-1] == s1[i-1]) )
                    dp[i][j] = 1;
            }
        }
        return dp[n][m];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << s.isInterleave(s1, s2, s3) << endl;
    return 0;
}
