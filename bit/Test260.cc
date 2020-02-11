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
    vector<int> singleNumber(vector<int>& nums) {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // eg ans is 3 & 5  diff = 3 ^ 5 = 011 ^ 101 = 110

        // diff 中位是1的地方必然是两个数字不相同的地方, 所以依据这个位可以将nums分成两组
        // 这里取最低位
        // Get its last set bit
        diff &= -diff;

        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums) {
            if ((num & diff) == 0) // the bit is not set and 如果两个数字相同必然分到一组
                rets[0] ^= num;
            else // the bit is set
                rets[1] ^= num;
        }
        return rets;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 1, 3, 2, 5};
    Solution s;
    auto ret = s.singleNumber(nums);
    cout << ret[0] << endl;
    cout << ret[1] << endl;
    return 0;
}
