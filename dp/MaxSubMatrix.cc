#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// 1D连续最长子序列
int maxSeq(vector<int>& nums) {
    int ans = 0, cur = 0, n = nums.size();
    for(int i = 0; i < n; i++) {
        cur = nums[i] + max(0, cur);
        ans = max(ans, cur);
    }
    return ans;
}


int maxSubMatrix(vector<vector<int>>& nums) {
    int n = nums.size(), m = nums[0].size(), maxsubrec = 0;
    vector<int> dp(m, 0);
    for(int i = 0; i < n; i++) {
        std::fill(dp.begin(), dp.end(), 0);
        for(int j = i; j < n; j++) {
            for(int k = 0; k < m; k++) {
                dp[k] += nums[j][k];

            }
            int curMax = maxSeq(dp);
            maxsubrec = max(maxsubrec, curMax);
        }
    }
    return maxsubrec;
}



int main(int argc, char const *argv[])
{
    vector<vector<int>> nums {
        {0, -2, -7, 0}, 
        {9 , 2, -6, 2},
        {-4, 1, -4, 1},
        {-1, 8, 0 ,-2}
    };
    cout << maxSubMatrix(nums) << endl;
    return 0;
}
