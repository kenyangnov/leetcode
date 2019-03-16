# 法一:pythonic
nums[:] = nums[len(nums)-k:]+nums[:len(nums)-k]

# 法二:部分逆置后整体逆置
nums[:len(nums)-k] = reversed(nums[:len(nums)-k])
nums[len(nums)-k:] = reversed(nums[len(nums)-k:] )
nums[:] = reversed(nums)