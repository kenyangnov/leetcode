class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ret;
    void dfs(int cur, int n, int k){
        if(temp.size()+(n-cur+1)<k){  //剪枝
            return;
        }
        if(temp.size()==k){
            ret.push_back(temp);
            return;
        }
        // if(cur==n+1){
        //     return;
        // }
        temp.push_back(cur);
        dfs(cur+1, n, k);
        temp.pop_back();
        dfs(cur+1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ret;
    }
};