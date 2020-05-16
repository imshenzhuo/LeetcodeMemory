#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // dp
    // bool canPartition(vector<int>& nums) {
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     if ((sum & 1) == 1) {
    //         return false;
    //     }
    //     int target = sum / 2;
    //     vector<bool> dp(target + 1, false);
    //     // dp[i] : nums的子集和是否可以等于i
    //     dp[0] = true;
        
    //     for (int num : nums) {
    //         // 每次更改都要参考前面的数据, 所以必须倒着来
    //         for (int i = target; i >= num; i--) {
    //             dp[i] = dp[i] || dp[i-num];
    //         }
    //     }
    //     return dp[target];
    // }

    // backtrace
    // 暴力回溯, 但是因为加入了排序以及简单剪枝, 效率也没有特别低
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        sum /= 2;
        // sort(nums.rbegin(),nums.rend());
        sort(nums.begin(),nums.end());
        return helper(nums, sum, 0);
    }
    bool helper(vector<int>& nums, int sum, int index){
        if (index >= nums.size())   return false;
        if (sum == nums[index])     return true;
        if (sum < nums[index])      return false;
        return helper(nums,sum-nums[index],index+1) || helper(nums,sum,index+1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{1,5,11,5};
    // vector<int> nums{1, 2, 5};
    cout << s.canPartition(nums) << endl;
    return 0;
}
