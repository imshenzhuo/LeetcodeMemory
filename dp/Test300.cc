#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
using namespace std;

// class Solution1 {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         const int size = nums.size();
//         if (size == 0)   return 0;
//         if (nums.size() == 1)   return 1;
//         int f[size];
//         f[0] = 1;
//         int res = 1;
//         for(int i=1; i<nums.size(); i++) {
//             for(int j=0; j<i; j++) {
//                 if (nums[j]<nums[i])    f[i] = max(f[i], f[j]+1);
//                 else f[i] = 1;
//             }
//             res = max(res, f[i]);
//         }
//         // for(int i=0; i<nums.size(); i++)    
//         //     cout << f[i] << endl;
//         return res;
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) 
                res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};

class Solution2 {
public:
    // There's a typical DP solution with O(N^2) Time and O(N) space 
    // DP[i] means the result ends at i
    // So for dp[i], dp[i] is max(dp[j]+1), for all j < i and nums[j] < nums[i]
    int lengthOfLIS(vector<int>& nums) {
        const int size = nums.size();
        if (size == 0) { return 0; } 
        vector<int> dp(size, 1);
        int res = 1;
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max (res, dp[i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums {2, 5, 3, 7, 11, 8, 10, 13, 6 };
    Solution s;
    s.lengthOfLIS(nums);
    // vector<int> nums = {10,9,2,5,3,7,101,18};
    // Solution1 s1;
    // auto a1 = s1.lengthOfLIS(nums);
    // cout << a1 << endl;

    // Solution2 s2;
    // auto a2 = s2.lengthOfLIS(nums);
    // cout << a2 << endl;
    return 0;
}

