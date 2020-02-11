#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
    void expand(vector<vector<char>>& grid, int x, int y, int& count) {
        count++;
        grid[x][y] = ' ';
        if (x > 0 && grid[x-1][y] == '1')               expand(grid, x-1, y, count);
        if (x < grid.size()-1 && grid[x+1][y] == '1' )  expand(grid, x+1, y, count);
        if (y > 0 && grid[x][y-1] == '1')               expand(grid, x, y-1, count);
        if (y < grid[0].size()-1 && grid[x][y+1] == '1')       expand(grid, x, y+1, count);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0, res = 0;
        while (count < n * m) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if (grid[i][j] == '1') {
                        expand(grid, i, j, count);
                        res++;
                    } else if (grid[i][j] == '0') {
                        count++;
                        grid[i][j] = ' ';
                    }
                }
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<char>> grid{
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution s;
    cout << s.numIslands(grid) << endl;
    return 0;
}
