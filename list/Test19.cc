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
class Solution {
public:
    
    ListNode* reverse(ListNode *head) {
        if (!head || !head->next)   return head;
        ListNode *t1 = head;
        ListNode *t2 = t1->next;
        t1->next = NULL;
        while(t2) {
            auto t3 = t2->next;
            t2->next = t1;
            t1 = t2;
            t2 = t3;
        }
        return t1;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        auto t = head;
        while(n>2) {
            t = t->next;
            n--;
        }
        if (t->next)
            t->next = t->next->next;
        return reverse(head);        
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    Solution s;
    s.removeNthFromEnd(head, 1);
    return 0;
}
