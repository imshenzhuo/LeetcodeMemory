/**
 * 非递归遍历树
 *      不管是队列还是栈, 方法都是一样的
 * 
 * 前序遍历
 */ 
#include <deque>
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

// class Solution {
// public:
//     vector<int> preorder(Node* root) {
//         vector<int> ivec;
//         vector<Node*> ptrVec;
//         if (root)  ptrVec.push_back(root);
//         while(!ptrVec.empty()) {
//             Node *t = ptrVec.back();
//             ivec.push_back(t->val);
//             ptrVec.pop_back();

//             while(!t->children.empty()) {
//                 ptrVec.push_back(t->children.back());
//                 t->children.pop_back();
//             }
//         }
//         return ivec;
//     }
// };

#pragma GCC optimize("Ofast")

__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> values;
        iterate(root, values);
        return values;
    }

    void iterate(Node* root, vector<int>& values) {
        if (!root) return ;

        deque<Node*> nodes;
        nodes.push_front(root);

        while (!nodes.empty()) {
            const auto node = nodes.front();
            nodes.pop_front();
            values.push_back(node->val);
            for (auto itr = node->children.rbegin(); itr != node->children.rend(); ++itr) {
                nodes.push_front(*itr);
            }
        }
    }
};