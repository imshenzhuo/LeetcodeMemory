#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)    return l2;
        if (!l2)    return l1;
        auto res = l1;
        int carry = 0;
        while(l1->next && l2->next) {
            l1->val += l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1->next == l2->next) {
            l1->val +=  l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
            if (caryy)  l1->next = new ListNode(1);
        }

        if (l2->next)   l1->next = l2->next;
        
        l1->val +=  l2->val + carry;
        carry = l1->val / 10;
        l1->val %= 10;
        while(l1->next) {
            l1 = l1->next;
            l1->val +=  carry;
            carry = l1->val / 10;
            l1->val %= 10;
        }
        if (carry)  l1->next = new ListNode(1);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
