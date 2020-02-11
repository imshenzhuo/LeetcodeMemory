#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
// #include <limit>
#include <algorithm>
using namespace std;


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // a = a + b 链表的这个好!麻!烦!
    ListNode* addList(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode(-1 * (1 << 30));
        head->next = a;
        auto it = head;
        while(it->next) {
            if (b->val >= it->val && b->val <= it->next->val) {

            }
            it = it->next;
        }
        return head->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int len = lists.size();
        if (len == 0)   return NULL;
        if (len == 1)    return lists[0];
        ListNode* res = lists[0];
        for(int i = 1; i < len; i++) {
            res = addList(res, lists[i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(5);

    ListNode *head0 = new ListNode(1);
    head0->next = new ListNode(3);
    head0->next->next = new ListNode(4);

    ListNode *head1 = new ListNode(2);
    head1->next = new ListNode(6);
    // head0->next->next = new ListNode(8);
    vector<ListNode*> ivec{head, head0, head1};


    Solution s;
    s.mergeKLists(ivec);
    // head = s.addList(head, head0);
    // while (head)
    // {
    //     cout << head->val << endl;
    //     head = head->next;
    // }
    
    return 0;
}
