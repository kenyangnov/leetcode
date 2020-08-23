class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> dp(size, 0);
        for (int i = 0; i < size; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// class Solution {
//    public:
//     int lengthOfLIS(vector<int>& nums) {
//         int size = nums.size();
//         if (size == 0) return 0;
//         vector<int> minVal(size + 1, 0);
//         int len = 1;
//         minVal[len] = nums[0];
//         for (int i = 1; i < size; i++) {
//             if (nums[i] > minVal[len]) {
//                 len++;
//                 minVal[len] = nums[i];
//             } else {
//                 int l = 1, r = len, pos = 0;
//                 while (l <= r) {
//                     int mid = (l + r) / 2;
//                     if (minVal[mid] < nums[i]) {
//                         pos = mid;
//                         l = mid + 1;
//                     } else {
//                         r = mid - 1;
//                     }
//                 }
//                 minVal[pos + 1] = nums[i];
//             }
//         }
//         return len;
//     }
// };