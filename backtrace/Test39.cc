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
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
/**
    回溯
        (所有递归) 没有必要写最后一步, 而是直接最后xx为null或者为0
    
 */

// class Solution {
// public:
//     void backtrace(vector<vector<int>> &res, vector<int> cur, vector<int>& candidates, int target, int begin = 0) {
//         if (target == 0)   {
//             res.push_back(cur);
//             return;
//         } 
//         if (begin == candidates.size()){
//             return;
//         }
//         if (target < candidates[begin])     return;
//         // for(int i = begin; i < candidates.size(); i++) {
//             backtrace(res, cur, candidates, target, begin + 1);
//             for(int j = 1; j * candidates[begin] <= target; j++) {
//                 cur.push_back(candidates[begin]);
//                 backtrace(res, cur, candidates, target - j * candidates[begin], begin + 1);
//             }
//         // }
//     }
    
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> res;
//         vector<int> cur;
//         backtrace(res, cur, candidates, target);
//         return res;
//     }
    
// };

int main(int argc, char const *argv[])
{
    vector<int> candidates = {2,3, 5};
    int target = 8;
    Solution s;
    auto ret = s.combinationSum(candidates, target);
    for(auto iv : ret) {
        for(auto i : iv) {
            cout << i << '\t';
        }
        cout << endl;
    }
    return 0;
}
