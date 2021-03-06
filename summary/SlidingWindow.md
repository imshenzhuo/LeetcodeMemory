滑动窗口可以巧妙的用线性时间解决很复杂的问题

## 使用
框架如下
```
初始化窗口;
for(i=1:n) {
    如果不符合条件
        窗口右端右移
    while (符合) {
        `更新结果` // 这里确保符合, 而且是全部的符合
        窗口左端右移
    }
}
```
## 举例 字符串匹配中的应用

### [3.无重复字符的最长子串](../hash/Test3.cc)

### [76.MinimumWindowSubstring](../binSearch_2Ptr/Test76.cc)
> Input: S = "ADOBECODEBANC", T = "ABC"
> Output: "BANC"


### [438.找到字符串中所有字母异位词](../binSearch_2Ptr/Test438.cc)
只需要把上题的条件限制一下就完全可以了

### 209.MinimumSizeSubarraySum
> 返回连续子序列大于目标value的最小长度
> Input: s = 7, nums = [2,3,1,2,4,3]
> Output: 2 : [4,3]

``` C++
int minSubArrayLen(int s, vector<int>& nums) {
    int res = INT_MAX;  // 结果
    int sum = 0;        // 判断是否符合条件中间值
    int left = 0;       // 窗口左端
    
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i]; // 窗口右端右移
        if (sum >= s) { // 如果符合条件
            res = min(res, i - left + 1); // 更新结果
            sum -= nums[left++];          // 窗口左端右移
        }
    }
    return res == INT_MAX ? 0 : res;
}
```