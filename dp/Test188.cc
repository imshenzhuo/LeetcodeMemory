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


// 把一次买/一次卖都当是一次交易，那么总的交易数字是2*k，0表示没有交易,0天代表没有股票
// dp[0][0] = 0 0天么有交易，钱最大是0
// dp[t][0] 当是第0天的时候，t(t>=1)次交易，第0天没有交易，所以是-100000

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(!prices.size()) return 0;
        if(k >= prices.size()/2)
        {
            int sum = 0;
            for(int i = 1; i < prices.size(); i++)
            {
                int val = prices[i] - prices[i - 1];
                sum += (val > 0? val: 0);
            }
            return sum;
        }

        vector<vector<int>> dp(k * 2 + 1, vector<int>(prices.size() + 1, 0));
        for(int t = 1; t <= 2 * k; t += 2)
            dp[t][0] = -1000000;

        for(int t = 1; t <= 2 * k; t++)
        {
            for(int i = 1; i <= prices.size(); i++)
            {
                if(t%2 == 1)//买入
                {   // 1. 前一天没有交易今天交易  dp[t-1][i-1] - prices[i-1] 或者前一天就t次交易了
                    // ps 因为i从1起所以-1
                    dp[t][i] = max(dp[t - 1][i - 1] - prices[i - 1], dp[t][i - 1]);
                }
                else//卖出
                {
                    dp[t][i] = max(dp[t - 1][i - 1] + prices[i - 1], dp[t][i - 1]);
                }
            }
        }
        return dp[k * 2][prices.size()];
    }
};




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


int main(int argc, char const *argv[])
{
    vector<int> ivec{3,3,5,0,0,3,1,4};
    Solution s;
    s.maxProfit(2, ivec);
    return 0;
}
