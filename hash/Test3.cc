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
//     int lengthOfLongestSubstring(string s) {
//         const int len = s.size();
//         unordered_map<char, int> m; // lookup table
//         int ans = 0; 
//         int start = 0; // current substring's first index
//         for(int i = 0; i < len; i++) {
//             if (m.find(s[i]) != m.cend() && m[s[i]] >= start)  { // in current substring not find or previous 
//                 ans = max(ans, i-start);  // 
//                 start = m[s[i]] + 1;
//             } 
//             m[s[i]] = i;
//         }
//         // 收集最后一次结果
//         return max(ans, len-start);
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[128];
        memset(m, -1, sizeof(m));
        int res = 0;
        int start = 0;
        for(int i = 0; i < s.size(); i++) {
            if (m[s[i]] != -1 && m[s[i]] >= start)  {
                res = max(res, i - start);
                start = m[s[i]] + 1;
            }
            m[s[i]] = i;

        }
        return max(res, (int)s.size() - start);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string ss = "bbbbbb";
    cout <<     s.lengthOfLongestSubstring(ss) << endl;
    
    return 0;
}