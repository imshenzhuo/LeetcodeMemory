#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i]) == 0)
                m[nums[i]] = i;
            else {
                res.push_back(i);
                res.push_back(m[target-nums[i]]);
                return res;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    auto a = s.twoSum(nums, target);
    a.size();
    return 0;
}
