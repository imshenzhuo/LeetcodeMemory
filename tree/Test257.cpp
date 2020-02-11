/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> svec;
        string s = to_string(root->val);
        help(svec, s, root->left);
        help(svec, s, root->right);
        return svec;
    }
    void help(vector<string> &svec, string s, TreeNode *t) {
        if (!t) return;
        if (t->left == t->right) {
            svec.push_back(s);
            return;
        }
        s += "->" + to_string(t->val);
        help(svec, s, t->left);
        help(svec, s, t->right);
        
    }
    
};