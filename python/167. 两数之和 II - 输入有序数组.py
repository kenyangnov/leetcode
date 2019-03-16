# 有序问题求指定值，使用对撞指针法，又叫做双索引法

for _ in range(len(nums)):
	if nums[l]+nums[r]>target:
		r-=1
	elif nums[l]+nums[r]<target:
		l+=1
	else:
		return [l, r]