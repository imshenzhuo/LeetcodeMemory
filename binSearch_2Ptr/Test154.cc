#include <cstdlib>
#include <climits>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;


// pretty good 

// class Solution {
// public:
//     int findMin(vector<int> &num) {
//         int lo = 0;
//         int hi = num.size() - 1;
//         int mid = 0;
        
//         while(lo < hi) {
//             mid = lo + (hi - lo) / 2;
            
//             if (num[mid] > num[hi]) {
//                 lo = mid + 1;
//             }
//             else if (num[mid] < num[hi]) {
//                 hi = mid;
//             }
//             else { // when num[mid] and num[hi] are same
//                 hi--;
//             }
//         }
//         return num[lo];
//     }
// };
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)     return nums[0];
        int lo = 0, hi = n - 1, mid;
        while (lo < hi && nums[lo] == nums[n-1]) {
            lo++;
        }
        if (nums[n-1] > nums[lo])    return nums[lo];
        int start = lo;
        while(lo < hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] >= nums[start])   lo = mid + 1;
            else hi = mid;
        }
        return nums[hi];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,2,2,0,1,1};
    Solution s;
    cout << s.findMin(nums) << endl;
    
    return 0;
}
