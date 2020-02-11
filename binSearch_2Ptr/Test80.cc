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
    int removeDuplicates(vector<int>& nums) {
        const int len = nums.size();
        if (len < 2)   return len;
        int index = 0;
        for(int i = 0; i < len - 2; i++) {
            if (nums[i] == nums[i+1] && nums[i+1] == nums[i+2])   
                continue;
            nums[index] = nums[i];
            index++;
        }
        return index;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ivec{1,1,1,2,2,3};
    Solution s;
    s.removeDuplicates(ivec);
    
    return 0;
}
