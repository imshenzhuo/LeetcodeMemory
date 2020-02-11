#include <cstdio>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTree(root, root->val);    
    }
    
    bool isUnivalTree(TreeNode* h, int val) {
        if (!h || h->val != val)    return false;  
        bool a = true, b = true;
        if (h->left)    a = isUnivalTree(h->left, val);
        if (h->right)   b = isUnivalTree(h->right, val);
        return a && b;
    }
};