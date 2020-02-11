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
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        return help(root).second;
    }
    
    pair<int,int> help(TreeNode *h) {
        if (h->left == h->right) {
            return make_pair(h->val, 0);
        }
        pair<int, int> left(0, -1);
        pair<int, int> right(0, -1);
        if (h->left)    left = help(h->left);
        if (h->right)   right = help(h->right);
        
        
    }
};