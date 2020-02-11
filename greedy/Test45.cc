#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
    int help(vector<int>& nums, int begin) {
        if (begin >= nums.size()-1){
            return 0;
        }
        if (begin + nums[begin] >= nums.size() - 1) 
            return 1;
        int m = INT_MAX - 10;
        int step = nums[begin];
        for(int i = step; i > 0; i--) {
            m = min(m, help(nums, begin + i));
        }
        return m + 1;
    }
public:
    int jump(vector<int>& nums) {
        return help(nums, 0);
    }
};


int main(int argc, char const *argv[])
{
    vector<int> ivec{5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    Solution s;
    cout << s.jump(ivec) << endl;
    return 0;
}
