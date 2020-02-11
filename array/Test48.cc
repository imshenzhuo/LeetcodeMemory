#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++) {
            int k = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);
            for(int j = 0; j < k; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1- i][n - 1 - j];
                matrix[n - 1- i][n - 1 - j] = matrix[j][n - 1- i];
                matrix[j][n - 1- i] = t;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    Solution s;
    s.rotate(matrix);
    for(auto m : matrix) {
        for(auto mm : m) {
            cout << mm << '\t';
        }
        cout << endl;
    }

    return 0;
}
