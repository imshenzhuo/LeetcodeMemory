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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root)  return nullptr;
        if (!inRange(root->val, L, R)) {
            if (root->val < L)  return trimBST(root->right, L, R);
            if (root->val > R)  return trimBST(root->left, L, R);
        }
            
        
        if (root->left) root->left = trimBST(root->left, L, R);
        if (root->right) root->right = trimBST(root->right, L, R);
        
        return root;
    }

    bool inRange(int val, int L, int R) {
        return val>=L && val<=R;
    }
    
    TreeNode* deleteNode(TreeNode* h, int val) {
        if (val > h->val)   h->right = deleteNode(h->right, val);
        else if (val < h->val)   h->left = deleteNode(h->left, val);
        else {
            // replace with get min val of right subtree
            if (h->left == h->right)  return nullptr;
            if (h->left) {
                // get max value in left subtree
                int replaceVal = getMax(h->left);
                h->val = replaceVal;
                h->left = deleteNode(h->left, replaceVal);
            } else {
                // get min value in right subtree
                int replaceVal = getMin(h->right);
                h->val = replaceVal;
                h->right = deleteNode(h->right, replaceVal);
            }
        }
        return h;
    }
    
    int getMax(TreeNode* h) {
        while(h->right)     h = h->right;
        return h->val;
    }
    
    int getMin(TreeNode* h) {
        while (h->left)     h = h->left;
        return h->val;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode n0(0), n1(1), n2(2);
    n1.left = &n0;
    n1.right = &n2;
    Solution sss;
    sss.trimBST(&n1 ,1,2);

    return 0;
}
