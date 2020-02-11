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
    int diameterOfBinaryTree(TreeNode* root) {
        return help(root).first;
    }
    pair<int,int> help(TreeNode* t) {
        if (!t || t->left == t->right)     return make_pair<int, int>(0, 0);
        auto left = help(t->left);
        auto right = help(t->right);
        pair<int, int> p;
        p.first = max(max(left.first, right.first), left.second+right.second+2);
        p.second = max(left.second, right.second) + 1;
        return p;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    int i = (bool)&n1 + (bool)&n2;
    cout << i << endl;

    Solution ss;
    cout << ss.diameterOfBinaryTree(&n1) << endl;



    return 0;
}
