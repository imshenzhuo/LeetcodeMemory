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
    int f(vector<int>& nums, int begin, int end, int S) {
        if (begin == end) {
            if (nums[begin] == S)   return 1;
            else    return 0;
        }
        return f(nums, begin + 1, end, S + nums[begin]) + f(nums, begin + 1, end, S - nums[begin]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return f(nums, 0, nums.size(), S);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{1,1,1,1,1};
    cout << s.findTargetSumWays(nums, 3) << endl;
    return 0;
}
