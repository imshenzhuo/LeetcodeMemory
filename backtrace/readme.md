回溯其实就是递归，l是解决以下问题为代表的利器

## 2^N的组合
比如得到一个集合的全部子集合 https://leetcode-cn.com/problems/subsets/ \
比如手机键盘的可能 https://leetcode-cn.com/problems/letter-case-permutation/ \
比如括号的生成 https://leetcode-cn.com/problems/generate-parentheses/submissions/ \

本质上是对参数中的某个元素取或者不取的全部穷举，但是可以用回溯和收集实现的非常优雅\
得到所有子集的实现
``` C++
vector<vector<int>> func(vector<int> nums) {
  vector<vector<int>> res;
  vector<int> cur;
  backtrace(res, cur, nums);
  return res;
}

void backtrace(vector<vector<int>> &res, vector<int> &cur, vector<int> &nums, int index = 0) {
  if (index == nums.size()){
    res.push_back(cur);
    return;
  }
  backtrace(res, cur, nums, index + 1);
  cur.push_back(nums[index]);
  backtrace(res, cur, nums, index + 1);
  cur.pop_back();
}
```

组合问题也2^N的遍历，只不过不是找出全部的组合，而是找出满足条件的组合
https://leetcode-cn.com/problems/combination-sum/

## N!的组合
比如 全排列 https://leetcode-cn.com/problems/permutations/ \
带有重复元素的全排列 https://leetcode-cn.com/problems/permutations-ii/ \

在这类问题中，不是简单的根据某个位置的元素有无做回溯，因为先后顺序不同，故需要添加标记位，确定该位置是否已被访问


## 回溯的回收
回溯函数的结构一般为
1. 退出条件
2. 下一步回溯

通常会构造一个唯一的当前变量，在退出条件中，如果满足则复制到结果。下一步回溯前后对该变量做修改和还原

