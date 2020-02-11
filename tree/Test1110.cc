#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
#include <algorithm>
using namespace std;

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        root = help(root, to_delete, res, true);
        return res;
    }
    TreeNode* help(TreeNode* node, vector<int>& to_delete, vector<TreeNode*>& res, bool flag) {
        if (!node)  return nullptr;
        
        
        if (find(to_delete.begin(), to_delete.end(), node->val) != to_delete.end() ) {
            flag = true;
            node->right = help(node->right, to_delete, res, flag);
            node->left = help(node->left, to_delete, res, flag);
            node->left = node->right = nullptr;
            delete node;
            return nullptr;
        } else {
            if (flag)   {
               res.push_back(node);
               flag = false;
            }
            node->right = help(node->right, to_delete, res, flag);
            node->left = help(node->left, to_delete, res, flag);
            return node;
        }
        
    }
};

int main(int argc, char const *argv[])
{
    const int n = 4;
    TreeNode* arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new TreeNode(i+1);
    }
    arr[0]->left = arr[1];
    arr[0]->right = arr[2];
    arr[2]->right = arr[3];

    // arr[1]->left = arr[3];
    // arr[1]->right = arr[4];

    // arr[2]->left = arr[5];
    // arr[2]->right = arr[6];


    Solution s;
    vector<int> ivec = {1, 2};
    auto i = s.delNodes(arr[0], ivec);

    for(auto ii : i) {
        cout << ii->val;
    }
    /* code */
    return 0;
}
