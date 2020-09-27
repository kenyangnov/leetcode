class Solution {
public:
    int numSquares(int n) {
        if (n == 0 || n == 1){
            return n;
        }
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        visited.insert(0);
        int step = 0;
        while(!q.empty()){
            step++;
            int size = q.size();
            for(int i=0;i<size;i++){
                int head = q.front();
                q.pop();
                for(int j=1;j*j+head<=n;j++){
                    if(j*j+head == n){
                        return step;
                    }
                    else{
                        if(visited.find(head+j*j)==visited.end()){
                            q.push(j*j+head);
                            visited.insert(j*j+head);
                        }
                    }
                }
            }
        }
        return -1;
    }
};