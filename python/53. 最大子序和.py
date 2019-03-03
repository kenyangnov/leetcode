class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        return self.divide(nums, 0, len(nums)-1)
        
    def divide(self, nums, l, r):
        if l > r:
            return -99999
			#注意此处不是返回0，比如｛-2，-1｝，
			#分治以后变为左中右:｛｝，-1，｛-2｝三部分。
			#左半部分｛｝应返回INT_MIN(-99999)，因为还要和右半部分的返回值进行比较,最终正确结果返回-1；
			#若左半部分返回0，0>-2,且大于左中右的最大组合值（-1），最终结果返回0，出错
        if l == r:
            return nums[l]
        mid = (l+r)/2
        left = self.divide(nums, l, mid-1)
        right = self.divide(nums, mid+1, r)
        temp = nums[mid]
        max_num = nums[mid]
        for i in range(mid-1, l-1,-1):
            temp += nums[i]
            max_num = max(max_num, temp)
        temp = max_num
        for i in range(mid+1, r+1):
            temp += nums[i]
            max_num = max(max_num, temp)
        return max(max(left, right), max_num)