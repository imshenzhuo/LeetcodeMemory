#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
using namespace std;

// class Solution {

// public:
    
//     // 闭区间
//     int help(vector<int>& prices, int start, int end) {
//         if (end == -1)  end = prices.size()-1;
//         if (start == end)   return 0;
//         int res = 0;
//         for(int i=start+1, imin=prices[start]; i<=end; i++) {
//             res = max(res, prices[i]-imin);
//             imin = min(imin, prices[i]);
//         }
//         return res;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         int res = 0;
//         for(int i=0; i<prices.size(); i++) {
//             // left [0,i]
//             int left = help(prices, 0, i);
//             // right [i+1,n)
//             int right = help(prices,i+1,-1);
//             res = max(res, left + right);
//         }
//         return res;
//     }
// };
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 0)   return 0;
        int res = 0;
        vector<int> FromLeft = { 0 }; // first day
        vector<int> FromRight = { 0 }; // first day
        for(int i=1, imax=prices[len-1], imin=prices[0]; i<len; i++) {
            FromLeft.push_back(max(prices[i] - imin, FromLeft[i-1]));
            imin = min(imin, prices[i]);
            FromRight.push_back(max(imax - prices[len-i-1], FromRight[i-1]) );
            imax = max(imax, prices[len-i-1]);
        }
        for(int i=0; i<len; i++) {
            res = max(res, FromLeft[i]+FromRight[len-1-i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> ivec = {3,3,5,0,0,3,1,4};
    // vector<int> ivec = {1, 2, 3, 4, 5};
    vector<int> ivec = {7,6,4,3,1};
    Solution s;
    auto i = s.maxProfit(ivec);
    cout << i << endl;
    return 0;
}
