#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int len = nums.size();
        if (len < 2)    return;
        int index = len - 2;
        while (index >= 0 && nums[index] > nums[index + 1]){
            index--;
        }
        if (index != -1) {
            for(int i = len - 1; i > index; i--) {
                if (nums[i] > nums[index]) {
                    swap(nums[index], nums[i]);
                    break;
                }
            }
        }
        int lo = index + 1, hi = len -1;
        while(lo < hi) {
            swap(nums[lo], nums[hi]);
            lo++; hi--;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,3};
    Solution s;
    s.nextPermutation(nums);
    return 0;
}
