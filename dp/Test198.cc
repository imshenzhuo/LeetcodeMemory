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
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)   return 0;
        if (len == 1)   return nums[0];
        nums[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++) {
            nums[i] = max(nums[i-2]+nums[i], nums[i-1]);
        }
        return nums[len-1];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,1};
    Solution s;
    s.rob(nums);

    return 0;
}
