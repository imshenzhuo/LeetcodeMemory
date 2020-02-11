#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int len = intervals.size();
        if (len < 2)    return intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {return a[0] < b[0]; });
        int index = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[index][1]) {
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            } else {
                index++;
                intervals[index] = intervals[i];
            }
        }
        return vector<vector<int>>(intervals.begin(), intervals.begin() + index + 1);
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> ivec{{1,3},{8,10},{2,6},{15,18}};
    Solution s;
    auto res = s.merge(ivec);
    cout << ivec[1][1] << endl;

    return 0;
}
