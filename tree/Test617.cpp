#include <stdio.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    int getValue(TreeNode* t) {
        if (!t) return 0;
        return t->val;
    }
    
    TreeNode* getLeft(TreeNode* t) {
        if (!t) return NULL;
        return t->left;
    }
    
    TreeNode* getRight(TreeNode* t) {
        if (!t) return NULL;
        return t->right;
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2)  return NULL;
        TreeNode *n = new TreeNode(getValue(t1) + getValue(t2));
        n->left = mergeTrees(getLeft(t1), getLeft(t2));
        n->right = mergeTrees(getRight(t1), getRight(t2));
        return n;
    }   
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
