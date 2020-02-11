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
    bool backtrace(vector<vector<char>>& board, string& word, int begin, int row, int col) {
        if (begin == word.size() - 1)
            return true;
        board[row][col] = ' ';
        
        if (row > 0 && board[row - 1][col] == word[begin + 1]) {
            if (backtrace(board, word, begin + 1, row - 1, col))
                return true;
        }
        if (row < board.size() - 1 && board[row + 1][col] == word[begin + 1]) {
            if (backtrace(board, word, begin + 1, row + 1, col))
                return true;
        }
        if (col > 0 && board[row][col - 1] == word[begin + 1]) {
            if (backtrace(board, word, begin + 1, row, col - 1))
                return true;
        }
        if (col < board[0].size() - 1 && board[row][col + 1] == word[begin + 1]) {
            if (backtrace(board, word, begin + 1, row, col + 1))
                return true;
        }
        board[row][col] = word[begin];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (backtrace(board, word, 0, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCB";

    cout << s.exist(board, word) << endl;
    return 0;
}
