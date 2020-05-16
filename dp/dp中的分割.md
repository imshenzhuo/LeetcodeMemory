[132. 给出把字符串全部分割成回文字符串的最小次数](https://leetcode.com/problems/palindrome-partitioning-ii/)
[1335. 一串数字分割成d段,求分割后每段最大数字之和](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/)

### T131

伪代码
输入 string s 
返回 int

``` bash
const int n = s.size();
vector<int> dp(n+1, 0); // eg dp[8] => s前8个s[0:8)的结果
// j = 从i到0 都是闭区间
for(int i = 0; i < n; i++) {
    for(int j = i; j >= 0; j--) {
        if s[j:i] 是回文字符串
            # dp[i]更新最小值, 既然s[j:i] 是回文字符串, 一刀剩下s[:j-1], 次数记录在dp[j]
            dp[i+1] = min(dp[i+1], dp[j] + 1);
    }
}
return dp[n];
```

s[j:i] 是否是回文字符串, 也同样需要dp存储


### T1335

```  bash
dp[i,j]前i天完成了j个任务的最小工作量(每天最大难度之和)
dp[i,j] = dp[i-1, i-1] + max(nums[i,j]) // 前i-1天完成i-1任务
dp[i,j] = dp[i-1, i] + max(nums[i+1,j]) // 前i-1天完成i任务
...
dp[i,j] = dp[i-1, j-1] + max(nums[j,j]) // 前i-1天完成j-1任务

dp[i,j]取最小即可

```

## 总结
dp最关键也是最难的地方在于状态的定义以及状态的转移

发现状态的定义一般两种情况
1. 直接就是问题 eg T1335 `dp[i,j]`直接定义为前i天完成j个任务
2. 对于序列数据 eg string array 通常分析从i到j的数据, 直接`dp[i,j]` eg 是不是回文

状态转移就要看题目而定了

看了答案懂了就是硬气 :)