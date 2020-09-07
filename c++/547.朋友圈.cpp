// DFS
class Solution1 {
   public:
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
        for (int j = 0; j < M.size(); j++) {
            if (M[i][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                dfs(M, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int rows = M.size(), cols = M[0].size();
        int ret = 0;
        vector<bool> visited(rows, 0);
        for (int i = 0; i < rows; i++) {
            if (visited[i] == 0) {
                dfs(M, visited, i);
                ret++;
            }
        }
        return ret;
    }
};

// 并查集
class Solution {
   public:
    int find(vector<int>& leader, int x) {
        int r = leader[x];
        while (r != leader[r]) {
            r = leader[r];
        }
        int cur = x, temp;
        while (leader[cur] != cur) {
            temp = leader[cur];
            leader[cur] = r;
            cur = temp;
        }
        return r;
    }
    void union_(vector<int>& leader, int x, int y) {
        int a = find(leader, x);
        int b = find(leader, y);
        if (a != b) {
            leader[a] = b;
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int rows = M.size(), cols = M[0].size();
        vector<int> leader(rows);
        for (int i = 0; i < rows; i++) leader[i] = i;
        int ret = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < i; j++) {
                if (M[i][j] == 1) {
                    union_(leader, i, j);
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            if (leader[i] == i) {
                ret++;
            }
        }
        return ret;
    }
};