class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ret = nums[0];
        for(int& val:nums){
            if(sum>0){
                sum += val;
            } else{
                sum = val;
            }
            ret = max(ret, sum);
        }
        return ret;
    }
};