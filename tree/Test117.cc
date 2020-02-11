#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <unordered_map>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)  return NULL;
        deque<Node*> dq;
        dq.push_front(root);
        int cur = 1;
        int next = 0;
        while(!dq.empty()) {
            auto node = dq.back(); dq.pop_back();
            cur--;
            if (node->left) {
                dq.push_front(node->left);
                next++;
            }
            if (node->right) {
                dq.push_front(node->right);
                next++;
            }
            if (cur == 0) {
                node->next = NULL;
                cur = next;
                next = 0;
            } else {
                node->next = dq.back();
            }
        }
        return root;
    }
};


int main(int argc, char const *argv[])
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    Solution s;
    root = s.connect(root);
    return 0;
}
