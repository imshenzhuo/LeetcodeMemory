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
    vector<TreeNode*> generateTrees(int n) {
        return help(1, n);
    }
    vector<TreeNode*> help(int start, int end) {
        vector<TreeNode*> tvec;
        for(int i=start; i<=end; i++) {
            vector<TreeNode*> left, right;
            if (i == start) left.push_back(nullptr);
            else    left = help(start, i-1);

            if (i == end)   right.push_back(nullptr);
            else    right = help(i+1, end);

            for(auto le : left) {
                for(auto ri : right) {
                    TreeNode *t = new TreeNode(i);
                    t->left = le;
                    t->right = ri;
                    tvec.push_back(t);
                }
            }                        
        }
        return tvec;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.generateTrees(3);
    return 0;
}
