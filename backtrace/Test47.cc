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
    void recursion(vector<int> num, int begin, vector<vector<int> > &res) {
        if (begin == num.size()-1) {
            res.push_back(num);
            return;
        }
        for (int k = begin; k < num.size(); k++) {
            if (begin != k && num[begin] == num[k]) continue;
            swap(num[begin], num[k]);
            recursion(num, begin + 1, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, res);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{1, 1, 1, 2, 2};
    auto ret =  s.permuteUnique(nums);
    for(auto r : ret) {
        for(auto rr : r) {
            cout << rr << '\t';
        }
        cout << endl;
    }
    return 0;
}
