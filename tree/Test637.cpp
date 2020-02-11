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
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        deque<TreeNode*> dq;
        dq.push_front(root);
        while(!dq.empty()) {
            double sum=0, cont=0;
            for(int i=0, len=dq.size(); i<len; i++) {
                TreeNode *n = dq.front(); dq.pop_front();
                if (n->left)    dq.push_back(n->left);
                if (n->right)   dq.push_back(n->right);
                sum += n->val;
                cont++;
            }
            res.push_back(sum/cont);
        }
        return res;
    }
};