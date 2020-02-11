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
    TreeNode* help(vector<int>& inorder, int start1, int end1, vector<int>& postorder, int start2, int end2) {
        if (start1 > end1 || start2 > end2) return NULL;
        // find root val in postorder
        TreeNode* root = new TreeNode(postorder[end2]);
        if (end2 == start2) return root;
        // find root val in indorder
        int index = start1;
        while(inorder[index] != postorder[end2])
            index++;
        // length of left sub tree
        // divide
        root->left = help(inorder, start1, index - 1, postorder, start2, start2 + index - start1 - 1);
        root->right = help(inorder, index + 1, end1, postorder, start2 + index - start1, end2 - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return help(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};