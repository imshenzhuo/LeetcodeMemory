/**
 * 非递归遍历树
 *      不管是队列还是栈, 方法都是一样的
 * 
 * 
 */ 

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ivec;
        vector<Node*> ptrVec;
        if (root)  ptrVec.push_back(root);
        while(!ptrVec.empty()) {
            Node *t = ptrVec.back();
            ivec.push_back(t->val);
            ptrVec.pop_back();

            while(!t->children.empty()) {
                ptrVec.push_back(t->children.back());
                t->children.pop_back();
            }
        }
        return ivec;
    }
};