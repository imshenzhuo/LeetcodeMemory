
动态规划

经典题目 

[最大连续子序列和](https://leetcode.com/problems/maximum-subarray/)
    变体 [最大连续子序列积](https://leetcode.com/problems/maximum-product-subarray/) tip 使用两个辅助变量
[最长升序LIS](https://leetcode.com/problems/longest-increasing-subsequence/)
    变体:   1.返回个数 (https://leetcode.com/problems/number-of-longest-increasing-subsequence/) ??
            2. https://leetcode.com/problems/increasing-triplet-subsequence/  ??
[rober问题](https://leetcode.com/problems/house-robber/)
    变体 robberii    ??
[stone Game](https://leetcode.com/problems/stone-game/)
    变体 game ii ??
1.11 update

目前遇到的dp根据问题类型可以分为两类
    1. 遍历所有情况求最大值
    2. 求满足target的数量
前者求最值就ok, 后者考虑的是"中间值". 前者求值后者求个数
eg 一维序列中连续序列sum的最大值&sum等于target的连续序列的个数

问题1 最长子序列和
定义状态: MaxSum[i]为包括第i个元素在内的从0到i的最长子序列和大小
状态转移: MaxSum[i+1] = s[i+1] + max(0, MaxSum[i+1])
求解: 遍历所有MaxSum[i], 选择最大的即可

问题2 满足最长子序列和目标值的个数
定义状态: sum[i,j]为第i个到第j个的序列和
状态转移: sum[i,j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]
    a | b
    -----
    c | d

    b = a + d - c

求解: 遍历每一个值统计即可


ps 空间复杂度可以优化为 O(N)

1.12
https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
https://leetcode.com/problems/minimum-falling-path-sum-ii/   理清题意 easy!
https://leetcode.com/problems/delete-and-earn/

另一种分类是根据状态转移过程
一些状态转移是只和某一个或者两个有关, 有的状态转移是和一组range的状态有关(最长升序子序列)

Longest Increment Subsequence
状态 
    dp[i] => 包含nums[i]的LIS值
状态转移: 
    如果包含nums[i], 那么**之前的**LIS是不能包含**大于**nums[i] 所以
    dp[i] = max{ dp[k] where `k<i` && `nums[k]<nums[i]`  }+ 1
ps. [NlogN)](https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/)


----------------------------------------------------------------------------

Minimum (Maximum) Path to Reach a Target
1. √ 746.Min Cost Climbing Stairs 
    state: dp[i] 是到第i个阶梯最小cost
    transform: dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
    ps: 典型的状态设定 转移简单涉及到前一个和前前一个
2. √ 64.Minimum Path Sum Medium √
    state: dp[i][j] 是grid[i][j]处的最小路径值
    transform: dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + grid[i][j];
    ps: 典型的状态设定 转移简单涉及到左一个和下一个
3. 322.Coin Change Medium √
    state: dp[i] 凑够i元需要的零钱个数
    transform: for each k  --> dp[i] = min(dp[i-k]) + 1 k是零钱的种类
    ps: 典型的状态设定 转移简单涉及的不是一个两个, 而是一个range
4. 931.Minimum Falling Path Sum Medium √
    tag : Very Easy
5. 983.Minimum Cost For Tickets Medium
6. 650.2 Keys Keyboard Medium
7. 279.Perfect Squares Medium √
    难一点的找零钱
8. 1049.Last Stone Weight II Medium
9. 120.Triangle Medium √
    tag: Very Easy
10. 474.Ones and Zeroes Medium 
11. 221.Maximal Square Medium √
    tag: 自己提出的堆叠
12. 1240.Tiling a Rectangle with the Fewest Squares Hard
13. 174.Dungeon Game Hard
14. 871.Minimum Number of Refueling Stops Hard

left 7

Distinct Ways
Merging Intervals
DP on Strings
Decision Making


有的dp是顺序遍历过程中, 从后往前的
eg 回文切割 & word break
``` C
for (int i = 0; i < s.size(); i++) {
    for(int j = i - 1; j >= 0; j++) {
        ...
    }
}
```
