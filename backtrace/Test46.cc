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
    
    void help(vector<bool>& flag, vector<int>& nums, vector<int> &cur, vector<vector<int>>&res, int count = 0) {
        if (count == nums.size()) {
            res.push_back(cur);
            return;
        }
        // 每次都要从头遍历
        for(int i = 0; i < nums.size(); i++) {
            if (!flag[i]) {
                flag[i] = true;
                cur[count] = nums[i];
                help(flag, nums, cur, res, count + 1);
                flag[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur = nums;
        vector<bool> flag(nums.size(), false);
        help(flag, nums, cur, res);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{1,2, 3};
    auto ret =  s.permute(nums);
    for(auto r : ret) {
        for(auto rr : r) {
            cout << rr << '\t';
        }
        cout << endl;
    }
    return 0;
}
