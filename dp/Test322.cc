#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
#include <algorithm>
using namespace std;

// dp[i][j] = max(dp[i−1][j], dp[i][j−w[i]]+v[i]) // j >= w[i]
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= coins.size(); i++)
            for(int j = coins[i-1]; j <= amount; j++){
                // 下行代码会在 1+INT_MAX 时溢出
                // dp[j] = min(dp[j], 1 + dp[j - coins[i-1]]); 
                if(dp[j] - 1 > dp[j - coins[i-1]])
                    dp[j] = 1 + dp[j - coins[i-1]];   
            }
        return dp[amount] == INT_MAX ? -1 : dp[amount];   
    }

};

// 贪心算法  不能解决问题
// eg coins = 2, 5, 9, 10
// amount = 14 
// 贪心 14 = 10 + 2 + 2
// 实际 14 = 9 + 5
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.begin(), coins.end());
//         int res = 0;
//         for(int i = coins.size() - 1; i >= 0; i--) {
//             while (coins[i] <= amount) {
//                 res++;
//                 amount -= coins[i];
//             }
//         }
//         if (amount == 0)    return res;
//         else    return -1;
//     }
// };

int main(int argc, char const *argv[])
{
    vector<int> coins {1, 2, 3, 5};
    int amount = 11;
    // vector<int> coins { 2 };
    // int amount = 3;
    Solution s;
    auto a = s.coinChange(coins, amount);
    cout << a << endl; 
    return 0;
}


