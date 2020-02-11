#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int len1 = haystack.size();
        const int len2 = needle.size();
        if (len2 == 0) return 0;
        if (len1 == len2)   return 0;
        for(int i = 0; i <= len1 - len2; i++){
            int j = 0;
            for(; j < len2; j++) {
                if (haystack[i+j] != needle[j])
                    break;
            }
            if (j == len2)  return i;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string haystack = "mississippi" , needle = "pi";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}
