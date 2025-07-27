class Solution:
    def setMatrixZeroes(self, mat):
        n, m = len(mat), len(mat[0])
        row0 = any(mat[0][j] == 0 for j in range(m))
        col0 = any(mat[i][0] == 0 for i in range(n))
        for i in range(1, n):
            for j in range(1, m):
                if mat[i][j] == 0:
                    mat[i][0] = mat[0][j] = 0
        for i in range(1, n):
            for j in range(1, m):
                if mat[i][0] == 0 or mat[0][j] == 0:
                    mat[i][j] = 0
        if row0:
            for j in range(m): mat[0][j] = 0
        if col0:
            for i in range(n): mat[i][0] = 0
