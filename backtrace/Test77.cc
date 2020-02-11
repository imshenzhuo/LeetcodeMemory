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
    void backtrace(vector<vector<int>>& res, vector<int>& base, vector<int>& cur, int begin, int k) {
        if (k == 0) {
            res.push_back(cur);
            return;
        }
        for(int i = begin; i <= base.size() - k; i++) {
            cur[cur.size() - k] = base[i];
            backtrace(res, base, cur, i + 1, k - 1);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> base;
        for(int i = 0; i < n; i++)  base.push_back(i+1);
        vector<int> cur(k, 0);
        backtrace(res, base, cur, 0, k);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto ret = s.combine(4,2);
    for(auto i : ret) {
        for(auto ii : i) {
            cout << ii << '\t';
        }
        cout << endl;
    }
    return 0;
}
