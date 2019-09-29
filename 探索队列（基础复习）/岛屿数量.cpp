class Solution {
private:
    int rows;
    int cols;
    int cnt;
    struct Loc{
        int i;
        int j;
        Loc(){};
        Loc(int x, int y):i(x),j(y){};
    };
    
    int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
    
    void BFS(Loc cur, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        queue<Loc> q;
        // if(visited[cur.i][cur.j]==0){ //进入函数前已经判断过，是合法数据
        q.push(cur);
        visited[cur.i][cur.j]=1;
        while(!q.empty()){
            int cur_i = q.front().i;
            int cur_j = q.front().j;
            for(int i=0;i<4;i++){
                int temp_i = cur_i + dir[i][0];
                int temp_j = cur_j + dir[i][1];
                if(temp_i>=0 && temp_i<rows && temp_j>=0 && temp_j<cols)    //注意判断边界
                    if(grid[temp_i][temp_j]=='1' && visited[temp_i][temp_j]==0){
                        q.push(Loc(temp_i, temp_j));
                        visited[temp_i][temp_j]=1;
                }
            }
            q.pop();
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)return 0;
        rows = grid.size();
        cols = grid[0].size();
        cnt = 0;
        vector<vector<bool>> visited(rows,vector<bool>(cols,0)); //初始化访问标记数组
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    cnt++;
                    BFS(Loc(i,j), grid, visited);
                }
            }
        }
        return cnt;
    }
};