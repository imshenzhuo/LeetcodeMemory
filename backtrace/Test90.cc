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
    void backtrace(vector<vector<int>>& res, vector<int>& cur, int begin, vector<int>& nums) {
        res.push_back(cur);
        if (begin == nums.size()) return;
        for(int i = begin; i < nums.size(); i++) {
            if (i == begin || nums[i] != nums[i-1]) {
                cur.push_back(nums[i]);
                backtrace(res, cur, i + 1, nums);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        backtrace(res, cur, 0, nums);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ivec{1, 2, 2};
    Solution s;
    s.subsetsWithDup(ivec);
    return 0;
}
