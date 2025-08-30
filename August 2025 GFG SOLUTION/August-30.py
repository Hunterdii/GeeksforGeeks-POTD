class Solution:
    def celebrity(self, m):
        n, c = len(m), 0
        for i in range(1, n):
            if m[c][i]: c = i
        for i in range(n):
            if i != c and (m[c][i] or not m[i][c]): return -1
        return c
