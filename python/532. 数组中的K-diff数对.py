# collections.Counter和set的使用
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