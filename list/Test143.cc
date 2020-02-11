#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         vector<ListNode*> nvec;
//         auto head_ = head;
//         while (head_) {
//             nvec.push_back(head_);
//             head_ = head_->next;
//         }
//         int len = nvec.size();
//         int last = (len)/2; 
//         int i = 0;
//         while(i != last) {
//             nvec[i]->next = nvec[len-1-i];
//             nvec[len-1-i]->next = nvec[++i];
//         }
//         nvec[last]->next = nullptr;
//     }
// };

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head)  return;
        vector<ListNode*> nvec;
        auto head_ = head;
        while (head_) {
            nvec.push_back(head_);
            head_ = head_->next;
        }
        int low = 0;
        int high = nvec.size()-1;
        auto handler = nvec[0];
        while(low<high) {
            handler->next = nvec[low];
            nvec[low]->next = nvec[high];
            handler = nvec[high];
            low++;
            high--;
        }
        if (low == high) {
            handler->next = nvec[low];
            nvec[low]->next = nullptr;
        }
    }
};

ListNode* makeN(int n) {
    ListNode *head = new ListNode(1);
    while (--n) {
        ListNode *t = new ListNode(n);
        t->next = head->next;
        head->next = t;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode* ln = makeN(1000);
    Solution s;
    s.reorderList(ln);
    cout << ln->val;
    return 0;
}
