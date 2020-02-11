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
    
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root)  return res;
        
        int lastVal = 0;
        int curDup = 0, curValSize = 0;
        help(root, res, curDup, curValSize, lastVal);
        return res;
    }
    
    void help(TreeNode* node, vector<int>& ivec, int& curDup, int& curValSize, int& lastVal) {
        if (!node)  return;
        if (node->left)     help(node->left, ivec, curDup, curValSize, lastVal);
        cout << node->val << endl;
        if (node->val == lastVal) {
            curValSize++;
            if (curValSize > curDup) {
                curDup = curValSize;
                ivec.clear();
                ivec.push_back(node->val);
            } else if (curValSize == curDup) {
                ivec.push_back(node->val);                
            }
        } else {
            curValSize = 1;
            if (curValSize >= curDup)  {
                curDup = curValSize;
                ivec.push_back(node->val);
            }  
            lastVal = node->val;    
        }
        
        
        if (node->right)    help(node->right, ivec, curDup, curValSize, lastVal);
    }
};

int main(int argc, char const *argv[])
{
    const int n = 7;
    TreeNode* arr[n+1];
    for(int i = 0; i <= n; i++) {
        arr[i] = new TreeNode(i);
    }
    arr[0]->val = arr[1]->val = arr[2]->val = 1;
    arr[3]->val = arr[4]->val = arr[5]->val = 2;

    arr[0]->right = arr[3];
    arr[3]->left = arr[1];
    arr[1]->right = arr[4];
    arr[4]->left = arr[2];
    arr[2]->right = arr[5];    

    Solution s;
    vector<int> ivec = s.findMode(arr[0]);
    for(auto i : ivec)  cout << i << endl;


    return 0;
}
