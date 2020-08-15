# leetocde tree 解题总结

递归遍历实际上是DFS深度优先搜索
非递归遍历实际上是BFS广度优先搜索

大部分的问题靠简单递归就可以解决
1. [Trim a Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/) (很久没看，这题咋一下差点把我整蒙了)
2. [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)
3. [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)最长路径 ❀


## 顺序遍历

1. [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)
2. [Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/) (不慌,写的比以前更好了)
3. [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)

### 先序遍历
非递归:  使用stack存储root节点 **stack**
```
        while stack 不为空
                从stack中pop出父节点
                父节点访问
                从后往前push父节点的子节点
```

[N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)



### 后序遍历
后序遍历的非递归要比先序遍历的非递归稍微麻烦一些 **stack + list**

#### 利用list等插入效率高的数据结构
``` cpp
list<int> res;
stack<Node*> nstack; nstack.push(root);
while(!nstack.empty()) {
    auto t = nstack.back(); nstack.pop();
    res.push_front(t->val);
    for(auto child : t->children) nstack.push(child);
}
return res;
```


#### 使用stack, 调整子节点顺序, 最后reverse
``` cpp
vector<int> res;
stack<Node*> nstack; nstack.push(root);
while(!nstack.empty()) {
    auto t = nstack.back(); nstack.pop();
    res.push_back(t->val);
    for(auto child : t->children) nstack.push(child);
}
return reverse(res.begin(), res.end());
```

> 发现个规律, 子节点的push 先序就反向 后序就正向

[N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)


### 中序遍历
只有二叉树才有中序遍历
``` c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        std::stack<TreeNode*> toVisit;
        while(1) {
            while(root) { toVisit.push(root); root=root->left; } // 掏空
            if(toVisit.empty()) break; 
            root=toVisit.top(); toVisit.pop(); // 掏空完了拿一个补充
            nodes.push_back(root->val); 
            root=root->right; // 准备继续掏空
        }
        return nodes;
    }
};
```


## 层次遍历
1. [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/)
2. [Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree/)


### 迭代方法
先序遍历使用stack, 层次遍历使用队列, 每次循环都将一层的Node入队
``` cpp
vector<vector<int>> res;
deque<TreeNode*> dq;
dq.push_front(root);

while(!dq.empty()) {
    res.push_back(vector<int>());
    for(int i=0, len=dq.size(); i<len; i++) { // 每次都确定好有几个Node要循环
        TreeNode *n = dq.front(); dq.pop_front();
        if (n->left)    dq.push_back(n->left);
        if (n->right)   dq.push_back(n->right);
        res.back().push_back(n->val);
    }
}
return res;
```



## path相关

1. [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/) 遍历 + 保存之前的信息
2. [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) 最长路径 ❀

## 其他
1. [二叉树变双向链表](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)
2. [树的子结构](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/)
3. [判断平衡二叉树](https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/) 编码设置-1是非平衡二叉树
4. [注意**叶子**](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

