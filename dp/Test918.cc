#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        const int n = A.size();
        int resmax = INT_MIN, resmin = INT_MAX, localmaxsum = 0, localminsum = 0, total = 0;
        for(int i = 0; i < n; i++) {
            localmaxsum = A[i] + max(0, localmaxsum);
            resmax = max(resmax, localmaxsum);
            localminsum = A[i] + min(0, localminsum);
            resmin = min(resmin, localminsum);
            total += A[i];
        }
        cout << resmax << endl;
        cout << resmin << endl;
        cout << total << endl;
        if (total == resmin) {
            return resmax;
        }
        return max(resmax, total - resmin);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ivec{-2, -3, -1};
    cout << s.maxSubarraySumCircular(ivec) << endl;
    return 0;
}
