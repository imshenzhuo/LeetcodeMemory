#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 1<<30;
        int sum = res;
        for(int i = 0; i < nums.size() - 2; i++) {
            int ttarget =  target - nums[i]; 
            int lo = i + 1, hi = nums.size() - 1;
            while(lo < hi) {
                int delta = abs(target - nums[i] - nums[lo] - nums[hi]);
                if (delta < res) {
                    res = delta;
                    sum =  nums[i] + nums[lo] + nums[hi];
                }
                if (nums[lo] + nums[hi] == ttarget) {
                    return target;
                } else if(nums[lo] + nums[hi] > ttarget) {
                    hi--;
                } else {
                    lo++;
                }
            }
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{1, 2, 5, 10, 11};
    int target = 12;
    cout << s.threeSumClosest(nums, target);

    return 0;
}
