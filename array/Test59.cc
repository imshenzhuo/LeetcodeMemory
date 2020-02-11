#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, -1));
        int row = 0, col = 0, index = 1;
        for(;;) {
            for(; col < n && res[row][col] == -1; col++) 
                res[row][col] = index++;
            if (index == n * n + 1) return res;
            col--; row++;
            
            for(; row < n && res[row][col] == -1; row++) 
                res[row][col] = index++;
            if (index == n * n + 1) return res;
            row--; col--;
            
            for(; col >= 0 && res[row][col] == -1; col--) 
                res[row][col] = index++;
            if (index == n * n + 1) return res;
            col++; row--;
            
            for(; col >= 0 && res[row][col] == -1; row--) 
                res[row][col] = index++;
            if (index == n * n + 1) return res;
            row++; col++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.generateMatrix(1);
    s.generateMatrix(3);
    s.generateMatrix(4);
    return 0;
}
