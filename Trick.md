## 线性表 stack queue list

1. 简单的表达式解析可以借助stack完成
2. 为了方便, 常常在链表的第一个元素之前放一个虚拟节点




## 树

完全二叉树的节点的子节点编号是2k 2k+1

### 二叉树使用
left == right 判断都是null也就是叶子节点

### 二叉树
递归首尾不要重复判断
``` C
    void getLeafSeq(TreeNode* h, vector<int> &ivec) {
        if (!h) return;
        if (!h->left && !h->right)   {
            ivec.push_back(h->val);
            return;
        }
        if (h->left)   // 没必要
            getLeafSeq(h->left, ivec);
        if (h->right) // 没必要
            getLeafSeq(h->right, ivec);
    }
```
但是可以减少函数开销 /笑哭

## 循环

``` cpp
for(int i = 0, n = q.size(); i < n; i++);
for(int i = 0; i < q.size(); i++);
```

## STL的使用

### vector
vector的push_back方法要拷贝, 所以1明显是优于2的
``` cpp
vector<vector<int>> ivvec;

// 1 
ivvec.push_back(vector<int>());
ivvec[0].push_back(...);

// 2
vector<int> ivec;
ivec.push_back(....);
ivvec.push_back(ivec);
```


### algorithm

[nth_element](https://www.inf.pucrs.br/~flash/lapro2ec/cppreference/w/cpp/algorithm/nth_element.html)


默认升序，使得[first, nth)的参数小于参数 [nth, last)，从而快速求得第k个参数

