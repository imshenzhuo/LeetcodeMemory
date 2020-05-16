#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // 任意两天之间的最大值
        int n = jobDifficulty.size();
        vector<vector<int>> diff(n, vector<int>(n,0));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if (j == i) diff[i][j] = jobDifficulty[j];
                else diff[i][j] = max(diff[i][j-1], jobDifficulty[j]);
            }
        }

        vector<vector<int>> dp(d, vector<int>(n,INT_MAX));
        for(int j = 0; j < n; j++) {
            dp[0][j] = diff[0][j];
        }
        for(int i = 1; i < d; i++) {
            for(int j = i; j < n; j++) {
                // 前i-1天完成了t个任务 最少i-1个 最多j-1个
                for(int t = i - 1; t < j ; t++) {
                    dp[i][j] = min(dp[i][j], dp[i-1][t] + diff[t+1][j]);
                }
            }
        }
        return dp[d-1][n-1];
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> ivec{7,1,7,1,7,1};
    // int d = 3;
    // vector<int> ivec{6, 5, 4, 3, 2, 1};
    // int d = 2;
    vector<int> ivec{11,111,22,222,33,333,44,444};
    int d = 6;
    Solution s;
    cout << s.minDifficulty(ivec, d) << endl;
    return 0;
}
