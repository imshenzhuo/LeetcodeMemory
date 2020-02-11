#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* help(ListNode* head, ListNode* end = NULL) {
        if (head == end)    return NULL;
        int len = 0;
        auto iter = head;
        while(iter != end) {
            iter = iter->next;
            len++;
        }
        iter = head;
        for(int i = 0; i < len / 2; i++)
            iter = iter->next;
        TreeNode *root = new TreeNode(iter->val);
        root->right = help(iter->next, end);
        root->left = help(head, iter);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        auto res = help(head);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ivec{1,2,3};
    ListNode *head = new ListNode(0);
    auto iter = head;
    for(auto i : ivec) {
        iter->next = new ListNode(i);
        iter = iter->next;
    }
    Solution s;
    s.sortedListToBST(head->next);
    return 0;
}
