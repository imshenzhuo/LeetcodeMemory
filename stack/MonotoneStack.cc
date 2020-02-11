#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * 单调递增stack
 * 
 * 可以在O(N)复杂度得到vector每个元素前一个更小元素和后一个更小元素
 * 
 * 
 * 
 */ 

vector<int> prevLess(vector<int>& A, stack<int> &in_stk) {
    vector<int> previous_less(A.size(), -1);
    for(int i = 0; i < A.size(); i++){
        while(!in_stk.empty() && in_stk.top() > A[i]){
            in_stk.pop();
        }
        previous_less[i] = in_stk.empty()? -1: in_stk.top();
        in_stk.push(A[i]);
    }
    return previous_less;
}

vector<int> nextLess(vector<int>& A, stack<int> &in_stk) {
    // next_less[i] = j means A[j] is the next less element of A[i].
    // next_less[i] = -1 means there is no next less element of A[i].
    vector<int> next_less(A.size(), -1);
    for(int i = 0; i < A.size(); i++){
        while(!in_stk.empty() && A[in_stk.top()] > A[i]){
            auto x = in_stk.top(); 
            in_stk.pop();
            next_less[x] = i;
        }
        in_stk.push(i);
    }
    return next_less;
}

int main(int argc, char const *argv[])
{
    vector<int> ivec = {3, 7, 8, 4};
    stack<int> ist;
    // auto ret = prevLess(ivec, ist);
    // while (!ist.empty()) {
    //     cout << ist.top() << endl;
    //     ist.pop();
    // }
    // for(auto i : ret) {
    //     cout << i << endl;
    // }

    auto ret = nextLess(ivec, ist);
    while (!ist.empty()) {
        cout << ivec[ist.top()] << " ";
        ist.pop();
    }
    cout << endl;
    for(auto i : ret) {
        cout << ivec[i] << " ";
    }
    cout << endl;
    
    return 0;
}
