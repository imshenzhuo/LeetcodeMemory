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
public:
    bool backtrace(vector<vector<char>>& board, vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& boxs, int begin) {
        if (begin == 81)    return true;
        int i = begin / 9, j = begin % 9;
        if (board[i][j] == '.') {
            for(int k =1; k <= 9; k++) {
                if (rows[i][k-1] == 0 && cols[k-1][j] == 0 && boxs[i/3*3+j/3][k-1] == 0) {
                    board[i][j] = k + '0';
                    rows[i][k-1] = 1;
                    cols[k-1][j] = 1;
                    boxs[i/3*3+j/3][k-1] = 1;
                    if (backtrace(board,  rows, cols, boxs, begin + 1)) return true;
                    board[i][j] = '.';
                    rows[i][k-1] = 0;
                    cols[k-1][j] = 0;
                    boxs[i/3*3+j/3][k-1] = 0;
                }
            }
        } else {
            return backtrace(board,  rows, cols, boxs, begin + 1);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> cols(9, vector<int>(9, 0));
        vector<vector<int>> boxs(9, vector<int>(9, 0));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    rows[i][board[i][j]-'1'] = 1;
                    cols[board[i][j]-'1'][j] = 1;
                    boxs[i/3*3+j/3][board[i][j]-'1'] = 1;
                }
            }
        }
        backtrace(board, rows, cols, boxs, 0);
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<char>> board {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    s.solveSudoku(board);
    for(auto v : board) {
        for(auto vv : v) {
            cout << vv << ' ';
        }
        cout << endl;
    }
    return 0;
}
