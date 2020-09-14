// TLE，待优化
class Solution1 {
public:
    vector<int> temp;
    vector<vector<int>> ret;
    set<vector<int>> st;
    void dfs(vector<int>&nums, int cur, int k){
        if(k==3){
            if(accumulate(temp.begin(), temp.end(), 0)==0){
                vector<int> temp_sort = temp;
                sort(temp_sort.begin(), temp_sort.end());
                if(st.find(temp_sort)==st.end()){
                    st.insert(temp_sort);
                    ret.push_back(temp_sort);
                }
            }
            return;
        }
        if(cur==nums.size()){
            return;
        }
        temp.push_back(nums[cur]);
        dfs(nums, cur+1, k+1);
        temp.pop_back();
        dfs(nums, cur+1, k);
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        dfs(nums, 0, 0);
        return ret;
    }
};

// 对撞指针
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int k=nums.size()-1, target = -nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                while(nums[j]+nums[k]>target && k>j){
                    k--;
                }
                if(j==k){
                    break;
                }
                if(nums[j]+nums[k]==target){
                    ret.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ret;
    }
};