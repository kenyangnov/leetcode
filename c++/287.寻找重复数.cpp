// 抽屉原理
// 找到num，它满足cnt[num-1]<=num-1且cnt[num]>num，其中cnt[k]为统计小于等于k的数据的数量。
// 即：k->抽屉数  cnt[k]苹果数
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1, mid;
        int cnt;
        while(left<right){
            cnt = 0;
            mid = left+(right-left)/2;
            for(int i=0; i<n; i++){
                cnt += (nums[i]<=mid);
            }
            if(cnt<=mid){
                left = mid + 1;
            } else{
                right = mid;
            }
        }
        return right;
    }
};