#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int len = nums.size();
        if (len == 0)   return -1;
        if (len == 1)  {
            if (nums[0] == target)  return 0;
            return -1;
        }
        // find p
        int lo = 0, hi = len - 1, mid = (lo + hi) / 2;
        while(lo <= hi) {
            if (nums[mid] > nums[mid + 1])  break;
            else {
                if (nums[mid] > nums[lo])   lo = mid + 1;
                else hi = mid - 1;
            } 
            mid = (lo + hi) / 2;
        }
        int end = mid;
        if(mid < len - 1 && nums[mid] < nums[mid + 1])
            end = len - 1;
        cout << end << endl;
        lo = end + 1, hi = end + len, mid = (lo + hi) / 2;
        while (lo <= hi) {
            if (nums[mid % len] > target)   hi = mid - 1;
            else if(nums[mid % len] < target) lo = mid + 1;
            else  return mid % len;
            mid = (lo + hi) / 2;
        }
        return -1;
    }
};


int main(int argc, char const *argv[])
{
    // vector<int> nums {4,5,6,7,8,0,1,2};
    vector<int> nums {1, 3, 5};
    int target = 0;
    Solution s;
    cout << s.search(nums, target) << endl;
    return 0;
}
