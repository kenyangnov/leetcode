//TLE，暴力解法
class Solution1 {
public:
    int findLHS(vector<int>& nums) {
        int ret = 0, cnt = 0;
        bool flag = false;
        for(int i=0; i<nums.size(); i++){
            cnt=0;
            flag = false;
            for(int j=0; j<nums.size(); j++){
                if((nums[j]-nums[i]==0)){
                    cnt++;
                }else if((nums[j]-nums[i]==1)){
                    cnt++;
                    flag = true;
                }
            }
            if(flag){
                ret = max(ret, cnt);
            }
        }
        return ret;
    }
};

// 哈希，两次遍历
class Solution2 {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int &val: nums){
            map[val]++;
        }
        int ret = 0;
        for(int &val: nums){
            if(map[val+1]){
                ret = max(ret, map[val]+map[val+1]);
            }
        }
        return ret;
    }
};

// 哈希，一次遍历
class Solution3 {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> map;
        int ret = 0;
        for(int &val: nums){
            map[val]++;
            if(map[val+1]){
                ret = max(ret, map[val]+map[val+1]);
            }
            if(map[val-1]){
                ret = max(ret, map[val]+map[val-1]);
            }
        }
        return ret;
    }
};