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
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res;
        for(int i=0; i<m; i++) {
            vector<int> t;
            for(int j=0;j<n;j++) {
                int sum = 0;
                for(int k = max(0,i-K); k<=min(i+K,n-1);k++) {
                    for(int h=max(0,j-K); h<=min(j+K,m-1);h++) {
                        sum += mat[k][h];
                    }
                }
                t.push_back(sum);
            }
            res.push_back(t);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> mat  =  {{67,64,78},{99,98,38},{82,46,46},{6,52,55},{55,99,45}};
    Solution s;
    s.matrixBlockSum(mat,3);
    return 0;
}
