#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <cassert>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    struct T{
        T():minNode(0),maxNode(0) {}
        TreeNode* minNode;
        TreeNode* maxNode;
    };
    
    void recoverTree(TreeNode* root) {
        T res;
        review (root, res);
        int a = res.minNode->val;
        res.minNode->val = res.maxNode->val;
        res.maxNode->val = a;
    }
    
    T* review(TreeNode* node, T &res) {
        if (!node)  return nullptr;
        
        if (node->left && node->val < node->left->val)  {
            res.minNode = node;
            res.maxNode = node->left;
            return nullptr;
        }
        if (node->right && node->val > node->right->val) {
            res.minNode = node;
            res.maxNode = node->right;
            return nullptr;;
        }
        
        
        T* left = review(node->left, res);
        if (left && left->maxNode->val > node->val)  {
            res.minNode = node;
            res.maxNode = left->maxNode;
            return nullptr;
        }
        T* right = review(node->right, res);
        if (right && right->minNode->val < node->val) {
            res.minNode = right->minNode;
            res.maxNode = node;
            return nullptr;
        }   
        T* t = new T();
        if (left)  t->minNode = left->minNode;
        else        t->minNode = node;
        if (right) t->maxNode = right->maxNode;
        else        t->maxNode = node;
        return t;
    }
};

TreeNode* constructTree1() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    // TreeNode* node4 = new TreeNode(4);
    // TreeNode* node5 = new TreeNode(5);
    // TreeNode* node6 = new TreeNode(6);
    node1->left = node3;
    // node1->right = node3;
    // node2->left = node4;
    // node3->left = node5;
    node3->right = node2;
    return node1;
}

TreeNode* constructTree2() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    // TreeNode* node5 = new TreeNode(5);
    // TreeNode* node6 = new TreeNode(6);
    node3->left = node1;
    // node1->right = node3;
    // node2->left = node4;
    // node3->left = node5;
    node3->right = node4;
    node4->left = node2;
    return node3;
}


void print(TreeNode *node) {
    if (!node)  return;
    print(node->left);
    cout << node->val << endl;
    print(node->right);
}

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode* root = constructTree1();
    s.recoverTree(root);
    print(root);
    
    TreeNode* root2 = constructTree2();
    s.recoverTree(root2);
    print(root2);

    return 0;
}
