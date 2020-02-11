#include <cstdlib>
#include <list>
#include <cstring>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
    void backtrace(vector<vector<int>>&res, vector<int>&cur, int k, int n, int lastVal = 0) {
        if (n < 0)  return;
        if (k == 0 && n == 0) {
            res.push_back(cur);
            return;
        }
        for(int i = lastVal + 1; i <= n; i++) {
            cur[cur.size()-k] = i;
            backtrace(res, cur, k - 1, n - i, i);
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur(k ,0);
        backtrace(res, cur, k, n);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.combinationSum3(2, 18);
    return 0;
}
