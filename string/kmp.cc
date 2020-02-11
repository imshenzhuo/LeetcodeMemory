/**
 * PMT:部分匹配表是指 从匹配字符串(短)的头到当前前缀后缀集合中某个元素的最长值
 * 
 * 
*/

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
    vector<int> kmpProcess(string needle) {
        vector<int> pmt(needle.size(), -1);
        int i = 0, j = -1;
        while(i < needle.size()) {
            if (j == -1 || needle[i] == needle[j]) {
                i++; j++;
                pmt[i] = j;
            } else {
                j = pmt[j];
            }
        }
        return pmt;
    }
    int strStr(string haystack, string needle) {
        
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    auto ret = s.kmpProcess("ababababca");
    vector<int> ivec{1,1,1};
    cout << ivec.size() << endl;
    // cout << ret.size() << endl;
    return 0;
}
