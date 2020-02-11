#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
// #include <unordered_map>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        if (target > d*f || target < d) return 0;
        vector<vector<int>> dp(d+1, vector<int>(target+1, 0));
        for(int i=1; i<=f && i<=target; i++) {
            dp[1][i] = 1;
        }
        for(int i=2; i<=d; i++) { //step
            for(int j=1; j<=target; j++) { // i步get j 
                if (j < i)  continue;
                for(int k=1; k<=f && j >= k; k++)
                    dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= (int)(1e9+7);
            }
        }
        return dp[d][target];
    }
};

int main(int argc, char const *argv[])
{
    // int d = 1, f = 6, target = 3;
    // int d = 2, f = 6, target = 7;
    // int d = 2, f = 5, target = 10;
    // int d = 1, f = 2, target = 3;
    int d = 30, f = 30, target = 500;
    Solution s;
    cout << s.numRollsToTarget(d,f,target) << endl;
    return 0;
}
