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
    int my_lower_bound(vector<vector<int>>& intervals, int val) {
        const int n = intervals.size();
        int lo = 0, hi = n - 1, mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (intervals[mid][0] > val)   hi = mid - 1;
            else if(intervals[mid][0] < val) lo = mid + 1;
            else return mid;
        }
        return -lo - 1;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0) return vector<vector<int>>(1, newInterval);
        
        if (newInterval[1] < intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        if (newInterval[0] > intervals[n-1][1]){
            intervals.push_back(newInterval);
            return intervals;
        }
            
        int insertIndex = my_lower_bound(intervals, newInterval[0]);
        if (insertIndex >= 0) {
            intervals[insertIndex][1] = max(intervals[insertIndex][1], newInterval[1]);
        } else {
            intervals.insert(intervals.begin()+(-insertIndex-1), newInterval);
            n++;
        }
        int index = 0, i = 1;
        for(; i < n; i++) {
            if (!(intervals[i][1] < intervals[index][0] || intervals[i][0] > intervals[index][1])) {
                intervals[index][0] = min(intervals[i][0], intervals[index][0]);
                intervals[index][1] = max(intervals[i][1], intervals[index][1]);
            } else {
                index++;
                intervals[index] = intervals[i];
            }
        }
        return vector<vector<int>>(intervals.begin(), intervals.begin()+index+1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> intervals{{1,5}};
    vector<int> newInterval = {1,7};
    auto ret = s.insert(intervals, newInterval);
    for(auto v : ret) {
        for(auto vv : v) {
            cout << vv << '\t';
        }
        cout << endl;
    }
    return 0;
}
