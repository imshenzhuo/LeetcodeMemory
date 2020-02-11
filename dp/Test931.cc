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
    int minFallingPathSum(vector<vector<int>>& A) {
        int len = A.size();
        if (len == 1)  return A[0][0];
        
        // 从倒数第二行开始
        for(int i=len-2; i>=0; i--) {
            A[i][0] += min(A[i+1][0], A[i+1][1]);
            for(int j = 1; j < len-1; j++) {
                A[i][j] += min( min(A[i+1][j], A[i+1][j-1]), A[i+1][j+1]);
            }
            A[i][len-1] += min(A[i+1][len-2], A[i+1][len-1]);
        }
        int res = A[0][0];
        for(int i=1; i<len; i++)    res = min(res, A[0][i]);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    // vector<vector<int>> A = { {1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> A = { {51,24},{-50,82}};
    Solution s;
    s.minFallingPathSum(A);
    return 0;
}
