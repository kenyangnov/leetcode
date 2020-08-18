class Solution {
   public:
    // 递归
    int binary_search(vector<int>& nums, int low, int high, int target) {
        if (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                return binary_search(nums, mid + 1, high, target);
            } else if (nums[mid] > target) {
                return binary_search(nums, low, mid - 1, target);
            } else {
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
    // 非递归
    // int search(vector<int>& nums, int target) {
    //     int low = 0, high = nums.size() - 1, mid;
    //     while(low<=high){
    //         mid = (low+high)/2;
    //         if(target<nums[mid]){
    //             high = mid-1;
    //         } else if(target>nums[mid]){
    //             low = mid+1;
    //         } else{
    //             return mid;
    //         }
    //     }
    //     return -1;
    // }
};