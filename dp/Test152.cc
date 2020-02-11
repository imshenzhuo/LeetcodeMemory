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
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        for(int i=1, imax = res, imin=res; i<nums.size(); i++) {
            if (nums[i] < 0 )   swap(imax, imin);
            imax = max(nums[i], imax*nums[i]);
            imin = min(nums[i], imin*nums[i]);
            res = max(res, imax);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ivec = {2,3,-2,4};
    Solution s;
    s.maxProduct(ivec);
    return 0;
}
