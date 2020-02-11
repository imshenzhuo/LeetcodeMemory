#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool greedy(int start, vector<int>& nums) {
        if (start == nums.size() - 1)   return true;
        for(int i = nums[start]; i > 0; i--) {
            if (start + i >= nums.size() - 1)   return true;
            if (greedy(start + i, nums))    return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        return greedy(0, nums);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{2};
    Solution s;
    cout << s.canJump(nums) << endl;
    return 0;
}
