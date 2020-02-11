#include <stack>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

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
    bool isValidBST(TreeNode* root) {
        if (!root)  return true;
        long last = (long)INT_MIN - 1;
        std::stack<TreeNode*> toVisit;
        while(1) {
            while(root) { toVisit.push(root); root=root->left; }
            if(toVisit.empty()) break;
            root = toVisit.top(); toVisit.pop();
            if (root->val <= last)  return false;
            last = root->val;
            // cout << root->val << endl;
            root=root->right;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(4);
    // root->right->left = new TreeNode(3);
    // root->right->right = new TreeNode(6);
    cout << s.isValidBST(root) << endl;
    return 0;
}
