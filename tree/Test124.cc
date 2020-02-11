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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        pair<int, int> a = help(root);
        return max(a.first, a.second);
    }
    // pair<int,int> curMax single
    pair<int, int> help(TreeNode* root) {
        if (root->left == root->right)  return pair<int,int>(root->val, root->val);
        pair<int, int> left = help(root->left);
        pair<int, int> right = help(root->right);
        // 
        int curMax = max(max(left.first, right.first), left.second+right.second+root->val);
        int singleMax = max(root->val+left.second, root->val+right.second);
        return pair<int, int>(curMax, singleMax);
    }
};

int main(int argc, char const *argv[])
{
    int a = max(2,3);
    return 0;
}
