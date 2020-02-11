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

    int getMin(vector<vector<int>>& arr, int level, int forbit) {
        int res;
        if (forbit == 0) {
            res = arr[level][1];
            for(int i=1; i<arr[level].size(); i++) {
                res = min(res, arr[level][i]);
            }
        } else {
            res = arr[level][0];
            for(int i=1; i<arr[level].size(); i++) {
                if (i == forbit)    continue;
                res = min(res, arr[level][i]);
            }
        }
        return res;
    }

    int minFallingPathSum(vector<vector<int>>& arr) {
        int len = arr.size();
        if (len == 1)   return arr[0][0];
        for(int i=len-2; i>=0; i--) {
            // arr[i][0] += arr[i+1][1];
            for(int j=0; j<len; j++) {
                arr[i][j] += getMin(arr, i+1, j);
            }
            // arr[i][len-1] += arr[i+1][len-2];
        }
        int res = arr[0][0];
        for(int i=1; i<len; i++)    res = min(res, arr[0][i]);
        return res;
    }
};


int main(int argc, char const *argv[])
{
    // vector<vector<int>> v = { {51,24},{-50,82}};
    // vector<vector<int>> v = { {1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> v = {{-73,61,43,-48,-36},{3,30,27,57,10},{96,-76,84,59,-15},{5,-49,76,31,-7},{97,91,61,-46,67}} ;
    Solution s;
    cout << s.minFallingPathSum(v) << endl;

    return 0;
}
