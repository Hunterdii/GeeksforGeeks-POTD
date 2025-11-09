class Solution: 
    def chocolatePickup(self, mat): 
        n, m = len(mat), len(mat[0])
        dp = [[[-1] * m for _ in range(m)] for _ in range(n)]
        
        def solve(i1, j1, j2):
            i2 = i1 + j1 - j2
            if i1 >= n or i2 >= n or j1 >= m or j2 >= m or i2 < 0:
                return -10**8
            if mat[i1][j1] == -1 or mat[i2][j2] == -1:
                return -10**8
            if i1 == n - 1 and j1 == m - 1 and j2 == m - 1:
                return mat[i1][j1]
            if dp[i1][j1][j2] != -1:
                return dp[i1][j1][j2]
            res = -10**8
            for d1 in range(2):
                for d2 in range(2):
                    res = max(res, solve(i1 + 1 - d1, j1 + d1, j2 + d2))
            res += mat[i1][j1]
            if i1 != i2:
                res += mat[i2][j2]
            dp[i1][j1][j2] = res
            return res
        
        return max(0, solve(0, 0, 0))
