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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> ivec(2, 0)[2] ;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for(int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }
        return dp[n-1][0];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ivec{7,1,5,3,6,4};
    cout << s.maxProfit(ivec) << endl;
    return 0;
}
