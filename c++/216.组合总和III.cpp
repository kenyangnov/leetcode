class Solution1 {
public:
    vector<int> temp;
    vector<vector<int>> ret;
    void dfs(int cur, int n, int k){
        if(temp.size() + (9 - cur + 1) < k || temp.size() > k || n<0){
            return;
        }
        if(n==0 && temp.size()==k){
            ret.push_back(temp);
            return;
        }
        temp.push_back(cur);
        dfs(cur+1, n-cur, k);
        temp.pop_back();
        dfs(cur+1, n, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, n, k);
        return ret;
    }
};

class Solution2 {
public:
    vector<int> temp;
    vector<vector<int>> ret;
    bool check(int mask, int k, int n){
        temp.clear();
        for(int i=0; i<9; i++){
            if((1<<i) & mask){
                temp.push_back(i+1);
            }
        }
        return (temp.size()==k && accumulate(temp.begin(), temp.end(), 0) == n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        for(int mask=1; mask < (1<<9); mask++){
            if(check(mask, k, n)){
                ret.emplace_back(temp);
            }
        }
        return ret;
    }
};