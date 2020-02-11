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
    void stepSet(TreeNode* t, int n, int val) {
        while(--n) {
            if (t->left)   t = t->left;
            else    t = t->right;
        }
        if (!t->left)   t->left = new TreeNode(val);
        else    t->right = new TreeNode(val);
    }
    
    TreeNode* recoverFromPreorder(string S) {
        
        int num = 0;
        int index = 0;
        while(S[index]!='-') {
            num = num*10 + S[index] - '0';
            index++;
        }
        TreeNode* root = new TreeNode(num);
        num = 0;
        int end = S.size();
        
        while(index < end)  {
            int count = 0;
            while (index<end && S[index] == '-') {
                count++;
                index++;
            }
            num = 0;
            while(index<end && S[index] >= '0' && S[index] <= '9') {
                num = num*10 + S[index] - '0';
                index++;
            }
            stepSet(root, count, num);
        }
        return root;
    }
};


int main(int argc, char const *argv[])
{
    string s = "1-2--3--4-5--6--7";

    Solution so;
    so.recoverFromPreorder(s);
    
    return 0;
}
