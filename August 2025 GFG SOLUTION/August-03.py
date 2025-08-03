class Solution:
    def applyDiff2D(self, mat, opr):
        n, m = len(mat), len(mat[0])
        d = [[0] * (m + 1) for _ in range(n + 1)]
        
        for v, r1, c1, r2, c2 in opr:
            d[r1][c1] += v
            d[r1][c2 + 1] -= v
            d[r2 + 1][c1] -= v
            d[r2 + 1][c2 + 1] += v
        
        for i in range(n):
            for j in range(m):
                if i: d[i][j] += d[i - 1][j]
                if j: d[i][j] += d[i][j - 1]
                if i and j: d[i][j] -= d[i - 1][j - 1]
                mat[i][j] += d[i][j]
        return mat
