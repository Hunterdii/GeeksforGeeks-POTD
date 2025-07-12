class Solution:
    def maxGold(self, mat):
        n, m = len(mat), len(mat[0])
        for j in range(m - 2, -1, -1):
            for i in range(n):
                mx = 0
                for di in [-1, 0, 1]:
                    ni = i + di
                    if 0 <= ni < n:
                        mx = max(mx, mat[ni][j + 1])
                mat[i][j] += mx
        return max(mat[i][0] for i in range(n))
