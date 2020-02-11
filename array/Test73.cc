#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
// #include <limit>
#include <algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> rows(n, 1);
        vector<int> cols(m, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if (rows[i] == 0) {
                for(int j = 0; j < m; j++)  matrix[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++) {
            if (cols[i] == 0) {
                for(int j = 0; j < n; j++)  matrix[j][i] = 0;
            }
        }
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix{
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    Solution s;
    s.setZeroes(matrix);
    cout << "aa" << endl;
    return 0;
}
