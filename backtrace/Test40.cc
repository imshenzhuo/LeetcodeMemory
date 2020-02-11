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
    void backtrace(vector<vector<int>> &res, vector<int>& cur, vector<int>& candidates, int target, int begin = 0) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (begin == candidates.size())     return;
        int num = 0;
        for(int i = begin; i < candidates.size(); i++) {
            if (candidates[i] != candidates[begin]) break;
            num++;
        }
        for(int i = 0; i <= num; i++) {
            backtrace(res, cur, candidates, target - i * candidates[begin], begin + num);
            cur.push_back(candidates[begin]);    
        }
        for(int i = 0; i <= num; i++) {
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        backtrace(res, cur, candidates, target);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    Solution s;
    auto ret = s.combinationSum2(candidates, target);
    for(auto iv : ret) {
        for(auto i : iv) {
            cout << i << '\t';
        }
        cout << endl;
    }
    return 0;
}