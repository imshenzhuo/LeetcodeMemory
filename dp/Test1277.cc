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
    
    int count(vector<vector<int>>& matrix, int m, int n) {
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                res += matrix[i][j];
            }
        }
        return res;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        while (n>1 && m>1) {
            res += count(matrix, m, n);
            for(int i=0; i<=m-2; i++) {
                for(int j=0; j<=n-2; j++) {
                    if (matrix[i][j] && matrix[i][j+1] && matrix[i+1][j] && matrix[i+1][j+1])
                        matrix[i][j] = 1;
                    else 
                        matrix[i][j] = 0;
                }
            }
            n--;
            m--;
        }
        res += count(matrix, m, n);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v ={{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    Solution s;
    cout << s.countSquares(v) << endl;

    return 0;
}
