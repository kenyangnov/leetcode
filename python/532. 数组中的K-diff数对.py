# collections.Counter和set的使用

# Counter类的目的是跟踪值出现的次数。
# 它是一个无序的容器类型，以字典的键值对形式存储，其中元素作为key，其计数作为value。

class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cnt = 0
        if k<0:
            return 0
        elif k==0:
            c=collections.Counter(nums)
            for i in c.values():
                if i>1:
                    cnt+=1
            return cnt
        else:
            s=set(nums)
            for i in s:
                if (i+k) in s:
                    cnt+=1
            return cnt
			
# more pythonic
class Solution(object):
	def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
		if k<0:
			return 0
		elif k==0:
			return sum(v>1 for v in collection.Counter(nums).values())
		else:
			return len(set(nums) & set(i+k for i in nums))