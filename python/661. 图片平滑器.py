# padding技巧：使用-1来标记pad

class Solution(object):
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        row  = len(M) + 2
        col = len(M[0]) + 2
		
        # padding
        N = [[-1] + r + [-1] for r in M]
        N = [[-1] * col] + N +[[-1] * col]
        
        for r in range(1, len(N)-1):
            for c in range(1, len(N[0])-1):
                sub_matrix = [N[r-1][c-1], N[r-1][c], N[r-1][c+1], 
                              N[r][c-1], N[r][c], N[r][c+1],
                              N[r+1][c-1], N[r+1][c], N[r+1][c+1]
                             ]
                total, counter = 0, 0
                for e in sub_matrix:
                    if e != -1:
                        total += e
                    else:
                        counter += 1
					
                M[r-1][c-1] = total // (9 - counter)
                
        return M
		