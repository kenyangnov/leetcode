class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int row, int col, int len){
        if(word[len]!=board[row][col]){
            return false;
        }
        if(len==word.length()-1){
            return true;
        }
        bool ret = false;
        visited[row][col] = true;
        for(int i=0; i<4; i++){
            int row_temp = row+dir[i][0];
            int col_temp = col+dir[i][1];
            if(row_temp>=0 && row_temp<board.size() && col_temp>=0 && col_temp<board[0].size() && !visited[row_temp][col_temp]){
                ret = dfs(board, word, visited, row_temp, col_temp, len+1);
                if(ret){
                    break;
                }
            }
        }
        visited[row][col] = false;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(dfs(board, word, visited, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};