# 标记位置可以通过取相反数实现，利用下标这个维度信息

for data in nums:
	index = abs(data)-1	#abs是必须的，因为有可能把后面的数取相反数
		if nums[index]>0:
			nums[index] = -nums[index]