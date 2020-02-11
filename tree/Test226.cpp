/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstdio>
#include <algorithm>
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)  return nullptr;
        myswap(root);
        if (root->left)     invertTree(root->left);
        if (root->right)    invertTree(root->right);
        return root;
    }
    
    void myswap(TreeNode *h) {
        swap(h,h);
        // TreeNode *t = h->left;
        // h->left = h->right;
        // h->right = t;
    }
};