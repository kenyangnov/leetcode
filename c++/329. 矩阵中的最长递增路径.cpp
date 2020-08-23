class Solution {
   public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>>& matrix, int rows, int cols, int rid, int cid, vector<vector<int>>& dp) {
        if (!dp[rid][cid]) {
            int maxVal = 1;
            for (int i = 0; i < 4; i++) {
                int rid_new = rid + dir[i][0];
                int cid_new = cid + dir[i][1];
                if (rid_new < rows && rid_new >= 0 && cid_new < cols && cid_new >= 0) {
                    if (matrix[rid_new][cid_new] > matrix[rid][cid]) {
                        maxVal = max(maxVal, dfs(matrix, rows, cols, rid_new, cid_new, dp) + 1);
                    }
                }
            }
            dp[rid][cid] = maxVal;
        }
        return dp[rid][cid];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxVal = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int temp = dfs(matrix, rows, cols, i, j, dp);
                maxVal = max(maxVal, temp);
            }
        }
        return maxVal;
    }
};