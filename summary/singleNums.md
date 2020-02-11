1. T136 除了有一个数字出现一次外所有数字出现两次, 找出那一个数字
2. T137 除了有一个数字出现一次外所有数字出现三次, 找出那一个数字
3. T260 除了有两个数字出现一次外所有数字出现两次, 找出那两个数字

### T136 One pass
``` C++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1)   return nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            res ^= nums[i];
        }
        return res;
    }
};
```

### T137
basic idea是按照bit统计个数 如果满3就清零
``` C++ 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0, mask = 0;
         
        for (int i : nums) {
            x2 ^= x1 & i;
            x1 ^= i;
            mask = ~(x1 & x2);
            x2 &= mask;
            x1 &= mask;
        }

        return x1;  // Since p = 1, in binary form p = '01', then p1 = 1, so we should return x1. 
                    // If p = 2, in binary form p = '10', then p2 = 1, and we should return x2.
                    // Or alternatively we can simply return (x1 | x2).
    }
};
```


### T260 Two pass
T136的增强版 和T137关系不大

``` C++
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
```