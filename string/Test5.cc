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
// public:
//     string longestPalindrome(string s) {
//         const int len = s.size();
//         int index1 = 0, index2 = 1;
//         for(int i=0; i<len; i++) {
//             for(int j=0; j<i; j++) {
//                 int start = j, end = i;
//                 for(; end > start ; start++, end--) {
//                     if (s[start] != s[end])     break;
//                 }
//                 if (end <= start && i - j + 1 > index2 - index1) {
//                     index1 = j;
//                     index2 = i + 1;
//                 }  
//             }
//         }
//         return s.substr(index1, index2-index1);
//     }
// };

/*
    能用什么神奇手段可以吧复杂度降低 (原来是O(N^3))
*/

// 暴力超时
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         const int len = s.size();
//         int index1 = 0, index2 = 1;
//         for(int i=0; i<len; i++) {
//             for(int j=0; j<i; j++) {
//                 int start = j, end = i;
//                 for(; end > start ; start++, end--) {
//                     if (s[start] != s[end])     break;
//                 }
//                 if (end <= start && i - j + 1 > index2 - index1) {
//                     index1 = j;
//                     index2 = i + 1;
//                 }  
//             }
//         }
//         return s.substr(index1, index2-index1);
//     }
// };

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         const int len = s.size();
//         if (len == 1)   return s;
//         int cur_len = 1, index1 = 0, index2 = 0;
//         for(int i = 1; i < len; i++) {
//             // s[i] center
//             int t = 0;
//             while(i - (t+1) >= 0 && i + (t+1) < len) {
//                 if (s[i-t-1] == s[i+t+1])   t++;
//                 else    break;
//             }
//             if (2 * t + 1 > cur_len) {
//                 cur_len = 2 * t + 1;
//                 index1 = i - t;
//                 index2 = i + t;
//             }
//             // (:i) [i:)
//             t = 0;
//             while(i - t - 1 >= 0 && i + t < len) {
//                 if (s[i-(t+1)] == s[i+t]) t++;
//                 else break;
//             }
//             if (2 * (t) > cur_len) {
//                 cur_len = 2 * (t);
//                 index1 = i - (t);
//                 index2 = i + (t-1);
//             }
//         }
//         return s.substr(index1, index2-index1+1);
//     }
// };

class Solution {
public:
    string longestPalindrome(string s) {
        const int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int i=0; i<len; i++)    dp[i][i] = true;
        int index1 = 0, index2 = 0;
        for(int i=1; i<len; i++)   {
            dp[i-1][i] = (s[i-1] == s[i]);
            if (dp[i-1][i]) {
                index1 = i-1;
                index2 = i;
            }
        }
        for(int i=0; i<len-2; i++) { // i => row
            for(int j=0; j<len-2-i; j++) {
                if (s[j] == s[j+2+i] && dp[j+1][j+i+1]) {
                    dp[j][j+2+i] = true;
                    index1 = j, index2 = j+2+i;
                }
            }
        }
        return s.substr(index1, index2-index1+1);
    }
};

int main(int argc, char const *argv[])
{
    string ss = "babad";
    Solution s;
    cout << s.longestPalindrome(ss) << endl;
    return 0;
}
