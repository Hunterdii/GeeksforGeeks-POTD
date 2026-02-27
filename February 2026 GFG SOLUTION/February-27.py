class Solution:
    def countSquare(self, mat, x):
        n, m, cnt = len(mat), len(mat[0]), 0
        pre = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1]
        for sz in range(1, min(n, m) + 1):
            for i in range(sz, n + 1):
                for j in range(sz, m + 1):
                    if pre[i][j] - pre[i-sz][j] - pre[i][j-sz] + pre[i-sz][j-sz] == x:
                        cnt += 1
        return cnt
