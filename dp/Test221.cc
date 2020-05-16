#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

// 特点: 正方形
// dp[i,j] = min(dp[i-1,j-1], dp[i-1,j], dp[i, j-1]) + 1

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    dp[i+1][j+1] = min(dp[i][j+1], min(dp[i+1][j], dp[i][j])) + 1;
                } else {
                    dp[i+1][j+1] = 0;
                }
                res = max(res, dp[i+1][j+1]);
            }
        }
        return res * res;
    }
};