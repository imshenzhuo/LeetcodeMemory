#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
using namespace std;

// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> lib;
//         vector<int> dp(n+1, n);
//         for(int base=1; base*base<=n; base++)    lib.push_back(base*base);
//         for(auto i : lib)   dp[i] = 1;
//         for(int i=1; i<=n; i++) {
//             for(auto c : lib) {
//                 if (i-c > 0)
//                     dp[i] = min(dp[i],1+dp[i-c]);
//             }
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int numSquares(int n) {
        vector<int> lib;
        vector<int> dp(n+1, -1);
        for(int base=1; base*base<=n; base++)    
            lib.push_back(base*base);
        for(auto i : lib)   
            dp[i] = 1;
        dp[0] = 0;
        help(dp, lib, n);
        return dp[n];
    }

    void help(vector<int>& dp, vector<int>& lib, int n) {
        int t = INT_MAX;
        for(auto k : lib) {
            if (k == n) {
                t = 0;
                break;
            }
            if (k > n)  continue;
            if (dp[n-k] == -1) help(dp, lib, n-k);
            t = min(t, dp[n-k]);
        }
        dp[n] = t + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.numSquares(16) << endl;
    return 0;
}
