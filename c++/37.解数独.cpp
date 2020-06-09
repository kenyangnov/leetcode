#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<char>>& board, int r, int c, char n) {
    for (int i = 0; i < 9; i++) {
        if (board[r][i] == n) return false;
        if (board[i][c] == n) return false;
        if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == n) return false;
    }
    return true;
}
bool backTrack(vector<vector<char>>& board, int i, int j) {
    int m = 9, n = 9;
    // 到达行末则换行
    if (j == n) {
        return backTrack(board, i + 1, 0);
    }
    // 最后行号为 m-1 ，i==m 时已经穷举完最后一行，结束递归
    if (i == m) {
        return true;
    }
    // 该位置是数字，则不用填写
    if (board[i][j] != '.') {
        return backTrack(board, i, j + 1);
    }
    // 主流程
    for (char ch = '1'; ch <= '9'; ch++) {
        if (!isValid(board, i, j, ch)) {
            continue;
        }
        board[i][j] = ch;
        if (backTrack(board, i, j + 1)) {
            return true;
        }
        board[i][j] = '.';
    }
    return false;
}
void solveSudoku(vector<vector<char>>& board) { backTrack(board, 0, 0); }

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    system("pause");
}