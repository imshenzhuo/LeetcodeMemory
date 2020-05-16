#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
using namespace std;


bool cmp(vector<int>& a, vector<int> &b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int ans = 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            int j = i - 1;
            while( j > 0 && envelopes[j-1][1] < envelopes[i-1][1])
            for(int j = i - 1; j >= 0; j--) {
                if (j == 0 || ) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                    // break;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    // [[30,50],[12,2],[3,4],[12,15]]

    vector<vector<int>> envelopes{
        {30,50},
        {12,2},
        {3,4},
        {12,15},
    };
    Solution s;
    cout << s.maxEnvelopes(envelopes) << endl;
    return 0;
}
