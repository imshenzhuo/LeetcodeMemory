/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto node = head;
        if (!node || !node->next)
            return head;
        head = node->next;
        while(node && node->next) {
            auto next = node->next->next;
            node->next->next = node;
            if (!next) {
                node->next = NULL;
            }
            else if (next->next)
                node->next = next->next;
            else 
                node->next = next;
            node = next;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    // ListNode *head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    Solution s;
    auto ret = s.swapPairs(nullptr);
    while(ret) {
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}
