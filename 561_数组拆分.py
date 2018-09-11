class Solution:
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
		//贪心思想
        nums.sort()
        n, sum = len(nums), 0
        for i in range(0, n, 2):	//Python循环的写法
            sum = sum + nums[i]
        return sum