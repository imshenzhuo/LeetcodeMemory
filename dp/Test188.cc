#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         if(!prices.size()) return 0;
//         if(k >= prices.size()/2)
//         {
//             int sum = 0;
//             for(int i = 1; i < prices.size(); i++)
//             {
//                 int val = prices[i] - prices[i - 1];
//                 sum += (val > 0? val: 0);
//             }
//             return sum;
//         }

//         vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(prices.size() + 1, vector<int>(2, 0)));
//         // 不论是第0天还是0次交易都不可能持有股票
//         for(int t = 0; t <= k; t++)
//             dp[t][0][1] = -1000000;
//         for(int i = 0; i < prices.size(); i++)
//             dp[0][i][1] = -1000000;

//         for(int t = 1; t <= k; t++)
//         {
//             for(int i = 1; i <= prices.size(); i++)
//             {
//                 dp[t][i][0] = max(dp[t][i - 1][0], dp[t][i - 1][1] + prices[i - 1]);
//                 dp[t][i][1] = max(dp[t][i - 1][1], dp[t - 1][i - 1][0] - prices[i - 1]);
//             }
//         }
//         return dp[k][prices.size()][0];
//     }
// };






// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         if(!prices.size()) return 0;
//         if(k >= prices.size()/2)
//         {
//             int maxsumval = 0;
//             for(int i = 1; i < prices.size(); i++)
//                 if(prices[i] > prices[i - 1])
//                     maxsumval += prices[i] - prices[i - 1];
//             return maxsumval;
//         }
//         vector<vector<int>> dp(k + 1, vector<int>(prices.size() + 1, 0));

//         for(int t = 1; t <= k; t++)
//         {
//             for(int i = 1; i < prices.size(); i++)
//             {
//                 int val = 0;
//                 for(int j = 0; j <= i; j++)
//                 {
//                     val = max(val, prices[i] - prices[j] + dp[t - 1][j]);
//                 }
//                 dp[t][i] = max(dp[t][i - 1], val);
//             }
//         } 
//         return dp[k][prices.size() - 1];
//     }
// };

// dp0[i,j]第i天第j次购买股票的收益


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp0(n+1, vector<int>(k+1, 0));
        vector<vector<int>> dp1(n+1, vector<int>(k+1, 0));

        // 初始值有点迷, 不持有股票的dp0[0][i]也不可能啊
        for(int i = 0; i <= n; i++)     dp1[i][0] = -100000;
        for(int i = 0; i <= k; i++)     dp1[0][i] = -100000;


        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                dp0[i][j] = max(dp0[i-1][j], dp1[i-1][j] + prices[i-1]);
                dp1[i][j] = max(dp1[i-1][j], dp0[i-1][j-1] - prices[i-1]);
            }
        }
        return dp0[n][k];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ivec{2,4,1};
    Solution s;
    cout << s.maxProfit(2, ivec) << endl;
    return 0;
}

