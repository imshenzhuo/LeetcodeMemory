#include <cstdlib>
#include <climits>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

/**
用match的个数判断
高级!
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int start = 0, minLen = INT_MAX;
        int left = 0, right = 0, n = s.size();
        for(char ch : t)    need[ch]++;
        
        // 统计匹配个数
        int match = 0;
        
        while(right < n) {
            char c1 = s[right];
            // window add & update match
            if (need.count(c1)) {
                window[c1]++;
                if (window[c1] == need[c1])
                    match++;
            }
            right++;
            // left move
            while(match == need.size()) {
                // 记录结果
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if (need.count(c2)) {
                    window[c2]--;
                    if (window[c2] < need[c2])
                        match--;
                }
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};