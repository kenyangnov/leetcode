# 关键：找到最大的三个数和最小的两个数即可（不论正数或负数）

# pythonnic
nums.sort()
a = nums[0]*nums[1]*nums[-1]
b = nums[-1]*nums[-2]*nums[-3]
return max(a*b)

# O(log(n))
max_1, max_2, max_3 = -1001, -1001, -1001
        min_1, min_2 = 1001, 1001
        for i in range(len(nums)):
            if nums[i] > max_1:
                max_3 = max_2
                max_2 = max_1
                max_1 = nums[i]
            elif nums[i] > max_2:
                max_3 = max_2
                max_2 = nums[i]
            elif nums[i] > max_3:
                max_3 = nums[i]

            if nums[i] < min_1:
                min_2 = min_1
                min_1 = nums[i]
            elif nums[i] < min_2:
                min_2 = nums[i]
        return max(min_1*min_2*max_1, max_3*max_2*max_1)
