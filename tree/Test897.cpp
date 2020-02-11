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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ivec;
        traval(root, ivec);
        TreeNode* numb = new TreeNode(0);
        TreeNode* res = numb;
        for(int i=0, n=ivec.size(); i<n ;i++) {
            TreeNode* cur = new TreeNode(ivec[i]);
            res->right = cur;
            res = cur;
        }
        return numb->right;
        
    }
    void traval(TreeNode* h, vector<int>& ivec) {
        if (!h) return;
        if (h->left)  traval(h->left, ivec);
        ivec.push_back(h->val);
        if (h->right)   traval(h->right, ivec);
    }
};