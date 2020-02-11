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
        int lo = 0, hi = nums.size() - 1, mid = (lo + hi) / 2;
        while(lo <= hi) {
            if (nums[mid] > target) hi = mid - 1;
            else if (nums[mid] < target) lo = mid + 1;
            else    return mid;
            mid = (lo + hi) / 2;
        }
        // 如果没有找到, lo指向的是target应该在的位置, 负数代表没有找到
        // 减一是为了区分0的特殊情况  
        return -lo-1;
    }
};


int main(int argc, char const *argv[])
{
    // vector<int> nums {4,5,6,7,8,0,1,2};
    vector<int> nums {0,1,2, 4,5,6,7,8};
    int target = 9;
    Solution s;
    for(int i = -1; i < 10; i++) {
        cout << s.search(nums, i) << '\t';
    }
    cout << endl;
    return 0;
}
