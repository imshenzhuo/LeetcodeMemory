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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, index = m + n - 1;
        int p2 = n - 1;
        while(index >= 0 && p2 >= 0) {
            if (p1 < 0) {
                nums1[index] = nums2[p2];
                p2--;
            } else {
                if (nums1[p1] <= nums2[p2]) {
                    nums1[index] = nums2[p2];
                    p2--;
                } else {
                    nums1[index] = nums1[p1];
                    p1--;
                }
            }
            index--;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 {4,5,6,0,0,0}; int m = 3;
    vector<int> nums2 {1,2,3}; int n = 3;
    Solution s;
    s.merge(nums1, m, nums2, n);

    
    return 0;
}
