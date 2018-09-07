class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        R, C = len(A), len(A[0])    #行和列
        ans = [[None] * R for _ in range(C)]    #列表生成式，列表解析方式生成数组
        for r, row in enumerate(A):
            for c, val in enumerate(row):
                ans[c][r] = val
        return ans

        #Alternative Solution:
        #return zip(*A)
        