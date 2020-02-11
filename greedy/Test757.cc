#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
using namespace std;


class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int mmin = intervals[0][0], mmax=mmin+1, delta = intervals[0][1] - mmax;
        for(int i = 1; i < intervals.size(); i++) {
            auto &k = intervals[i];
            if(k[1] <= mmin) {
                mmin = k[1] - 1;
                delta = 0;
            } else if (k[0] >= mmax+delta) {
                mmin += delta;
                mmax = k[0] + 1;
            } else if (k[0] <= mmin && k[1]>= mmax+delta ) {

            } else { // 有交集
                // mmax - mmin = constant
                int length = mmax - mmin;
                if (k[0] > mmin && k[1] < mmax+delta) { // 内部
                    int a = max((k[0]+1-(mmax-mmin)), mmin);
                    int b = min((k[1]-1),(mmin+delta));
                    delta = b - a;
                    mmin = a;
                    mmax = mmin + length;
                } else if (k[0] < mmin) {  // left 交集
                    int newmin = max(mmin, k[1]-1);
                    delta = abs(mmin - (k[1]-1));
                    mmin = newmin;
                    mmax = mmin + length;
                } else if (k[1] > mmax+delta) {  // right 交集
                    int newmax = min(k[0]+1, mmax+delta);
                    delta = abs(mmax+delta - (k[0]+1));
                    mmax = newmax;
                    mmin = newmax - length;
                }
            }
        }
        return mmax - mmin + 1;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> intervals = {
        {2,10},{3,7},{3,15},{4,11},{6,12},{6,16},{7,8},{7,11},{7,15},{11,12}
    };
    
    cout << s.intersectionSizeTwo(intervals) << endl;
    return 0;
}
