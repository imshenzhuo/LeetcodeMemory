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


/**
 *  C++
 * 
 * 
 */ 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < len; i++) {
            if (i != 0 && nums[i] == nums[i-1])
                continue;
            int a = nums[i];
            unordered_map<int, int> m;
            for(int j = i + 1; j < len; j++) {
                // if (j != i + 1 && nums[j] == nums[j-1])
                //     continue;
                int target =  0 - a;
                if (m.find(target - nums[j]) != m.end()) {
                    if (m[target- nums[j]] == i + 1 || nums[m[target- nums[j]]] != nums[m[target- nums[j]]-1] ) {
                        vector<int> ivec {nums[i], nums[j], nums[m[0 - a - nums[j]] ] };
                        res.push_back(ivec);
                    }
                } else {
                    m[nums[j]] = j;
                }
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{0, 0, 0, 0};
    auto ret = s.threeSum(nums);
    for(auto r : ret) {
        for(auto rr : r) {
            cout << rr << '\t';
        }
        cout << endl;
    }
    return 0;
}
