#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 1)   return 1;
        int f[2002];
        f[0] = 1;
        int res = 1;
        for(int i=1; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
                if (nums[j]<nums[i])    f[i] = max(f[i], f[j]);
            }
            f[i]++;
            res = max(res, f[i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = { 1,3,5,4,7};
    Solution s;
    s.findNumberOfLIS(nums);
    return 0;
}

