滑动窗口可以巧妙的用线性时间解决很复杂的问题

## 使用
框架如下
```
初始化窗口;
for(i=1:n) {
    如果不符合条件
        窗口右端右移
    while (符合) {
        更新结果
        窗口左端右移
    }
}
```
## 举例

### 76.MinimumWindowSubstring
> Input: S = "ADOBECODEBANC", T = "ABC"
> Output: "BANC"



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