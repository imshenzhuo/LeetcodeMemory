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
    int numDecodings(string s) {
        const int len = s.size();
        if (len == 0)   return 0;
        if (len == 1)   return 1;
        vector<int> dp(len, 1);
        dp[0] = 1;
        if ( (s[0] - '0') * 10 + s[1] - '0' <= 26)
            dp[1] = 2;
        if (len == 2)   return dp[1];
        for(int i = 2; i < len; i++) {
            if ( (s[i-1] - '0') * 10 + s[i] - '0' <= 26) {
                dp[i] = dp[i-1] + dp[i-2];
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[len - 1];
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.numDecodings("1211") << endl;
    return 0;
}
