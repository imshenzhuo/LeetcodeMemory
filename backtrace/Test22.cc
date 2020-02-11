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

class Solution {
public:
    
    void backtrace(vector<string> &res, string& cur, int left, int right, int n) {
        if (right > left || right + left > 2 * n)   return;
        if (right == left && left == n) {
            res.push_back(cur);
            return;
        }
        cur[left + right] = '(';
        backtrace(res, cur, left + 1, right, n);
        cur[left + right] = ')';
        backtrace(res, cur, left, right + 1, n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur(2*n, '*');
        backtrace(res, cur, 0, 0, n);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.generateParenthesis(3);
    for(auto i : res) {
        cout << i << endl;
    }
    return 0;
}
