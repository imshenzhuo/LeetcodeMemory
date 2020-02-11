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
    
    void backtrace(vector<vector<int>>&res, vector<int>& nums, int begin, vector<int>& cur) {
        if (begin == nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[begin]);
        backtrace(res, nums, begin+1, cur);
        cur.pop_back();
        backtrace(res, nums, begin+1, cur);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrace(res, nums, 0, cur);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums {1,2,3};
    auto res = s.subsets(nums);
    for(auto i : res) {
        for(auto k : i)
            cout << k << '\t';
        cout << endl;
    }
    return 0;
}
