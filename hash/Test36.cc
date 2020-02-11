#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> arr {0, 0, 0, 0, 0, 0, 0, 0, 0};
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (arr[board[i][j] - '0']  != 0)  return false;
                    arr[board[i][j]- '0']++;
                }
            }
        }
        for(int i = 0; i < 9; i++)  arr[i] = 0;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (arr[board[j][i]- '0'] != 0)  return false;
                    arr[board[j][i]- '0']++;
                }
            }
        }
        
        for(int cent_x = 1; cent_x < 8; cent_x += 3) {
            for(int cent_y = 1; cent_y < 8; cent_y +=3) {
                for(int i = 0; i < 9; i++)  arr[i] = 0;
                if (arr[board[cent_x][cent_y]- '0'] != 0)  return false;
                arr[board[cent_x][cent_y]- '0']++;
                if (arr[board[cent_x-1][cent_y]- '0'] != 0)  return false;
                arr[board[cent_x-1][cent_y]- '0']++;
                if (arr[board[cent_x+1][cent_y]- '0'] != 0)  return false;
                arr[board[cent_x+1][cent_y]- '0']++;
                if (arr[board[cent_x][cent_y-1]- '0'] != 0)  return false;
                arr[board[cent_x][cent_y-1]- '0']++;
                if (arr[board[cent_x][cent_y+1]- '0'] != 0)  return false;
                arr[board[cent_x][cent_y+1]- '0']++;
                
                if (arr[board[cent_x+1][cent_y+1]- '0'] != 0)  return false;
                arr[board[cent_x+1][cent_y+1]- '0']++;
                if (arr[board[cent_x+1][cent_y-1]- '0'] != 0)  return false;
                arr[board[cent_x+1][cent_y-1]- '0']++;
                if (arr[board[cent_x-1][cent_y+1]- '0'] != 0)  return false;
                arr[board[cent_x-1][cent_y+1]- '0']++;
                if (arr[board[cent_x-1][cent_y-1]- '0'] != 0)  return false;
                arr[board[cent_x-1][cent_y-1]- '0']++;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board{
        {"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
    };
    Solution s;
    s.isValidSudoku(board);
    return 0;
}
