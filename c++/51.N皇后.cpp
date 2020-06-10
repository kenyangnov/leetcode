class Solution {
   public:
    vector<vector<string>> ans;
    bool isValid(vector<string>& board, int row, int col) {
        for (int i = 0; i < board.size(); i++) {
            if (board[row][i] == 'Q') return false;
            if (board[i][col] == 'Q') return false;
        }
        for (int i = 1; row - i >= 0 && col - i >= 0; i++) {
            if (board[row - i][col - i] == 'Q') return false;
        }
        for (int i = 1; row - i >= 0 && col + i < board.size(); i++) {
            if (board[row - i][col + i] == 'Q') return false;
        }
        return true;
    }
    void backTrack(vector<string>& board, int row) {
        int size = board.size();
        if (row == size) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < size; i++) {
            if (isValid(board, row, i)) {
                board[row][i] = 'Q';
                backTrack(board, row + 1);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s = "";
        for (int i = 0; i < n; i++) {
            s += '.';
        }
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        backTrack(board, 0);
        return ans;
    }
};