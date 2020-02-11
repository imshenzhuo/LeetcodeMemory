
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return help(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* help(vector<int>& preorder, vector<int>& inorder, int pstart, int pend, int istart, int iend) {
        if (pstart > pend || istart > iend) return nullptr;
        if (pstart == pend)   return new TreeNode(preorder[pstart]);
        
        int val  = preorder[pstart];
        TreeNode* node = new TreeNode(val);
        
        int index = find(inorder.begin(), inorder.end(), val) - inorder.begin();
        int len_left = index - istart;
        node->left = help(preorder, inorder, pstart+1, pstart+len_left, istart, index-1);
        node->right = help(preorder, inorder, pstart+len_left+1, pend, index+1, iend);
        return node;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution s;
    auto kk = s.buildTree(preorder, inorder);
    int a = 0;
    return 0;
}
