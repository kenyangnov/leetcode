class Solution {
/*
private:
    bool visited[10][10][10][10] = {0};
    
    char func_add(char c){
        int value = c - '0';
        value = (value + 10 - 1) % 10;
        return char(value);
    }
    char func_sub(char c){
        int value = c - '0';
        value = (value + 1) % 10;
        return char(value);
    }
    
    int BFS(vector<string>& deadends, string target, bool* &visited){
        int step = 0;
        queue<string> q;
        q.push("0000");
        visited[0][0][0][0] = true;
        while(!q.empty()){
			//此处少了一个循环
            string cur = q.front();
            q.pop();
            step++;
            string temp_i = cur;
            string temp_j = cur;
            for(int i=0;i<4;i++){
                temp_i[i] = func_add(temp_i[i]);
                temp_j[i] = func_sub(temp_j[i]);
                int i0,i1,i2,i3 = int(temp_i[0]),int(temp_i[1]),int(temp_i[2]),int(temp_i[3]);
                int j0,j1,j2,j3 = int(temp_j[0]),int(temp_j[1]),int(temp_j[2]),int(temp_j[3]);
                if(temp_i==target||temp_j==target){
                    return cnt;
                }
                if(find(deadends.begin(), deadends.end(), temp_i)==deadends.end() && visited[i0][i1][i2][i3]==0){
                    q.push(temp_i);
                    visited[i0][i1][i2][i3]=1;
                }
                if(find(deadends.begin(), deadends.end(), temp_j)==deadends.end() && visited[j0][j1][j2][j3]==0){
                    q.push(temp_j);
                    visited[j0][j1][j2][j3]=1;
                }
                temp_i = cur;
                temp_j = cur;
            } 
        }
        return -1;
    }
*/
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        string start = "0000";
        //unordered_set使用，保存不能访问或者已访问的元素
        unordered_set<string> hash_dead;
        unordered_set<string> visited;
        visited.insert(start);
        //c++中for的另一种写法
        for (string itm : deadends) hash_dead.insert(itm);
        if (hash_dead.find(start) != hash_dead.end()) return -1;
        int ans = 0;
        q.push(start);
        while(!q.empty()){
            //总忘记BFS这个循环，导致变成DFS
            for(int i=q.size();i>0;i--){
                string top=q.front();
                q.pop();
                if(top.compare(target) == 0) return ans;
                string backup = top;
                for(int j=0;j<4;j++){
                    top[j] = (top[j] - '0' + 1) % 10 + '0';
                    if (visited.find(top) == visited.end() && hash_dead.find(top)== hash_dead.end()) {
                        visited.insert(top);
                        q.push(top);
                    }				
                    top[j]= (top[j] - '0' +8) % 10 + '0';
                    if (visited.find(top) == visited.end() && hash_dead.find(top) == hash_dead.end()) {
                        visited.insert(top);
                        q.push(top);
                    }
				    top = backup;
                }
            }
            ans++;
        }
        return -1;
    }
};