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
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));
        for(int i = 1; i <= N; i++) {
            dp[1][i] = i;
        }
        for(int i = 1; i <= K; i++) {
            dp[i][1] = 1;
            dp[i][0] = 0;
        }
        for(int i = 2; i <= K; i++) {
            for(int j = 2; j <= N; j++) {
                for(int k = 1; k <= j; k++) {
                    int t = max(dp[i-1][k-1], dp[i][j-k]) + 1;
                    dp[i][j] = min(dp[i][j], t);
                }
            }
        }
        return dp[K][N];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.superEggDrop(2, 100) << endl;
    return 0;
}
