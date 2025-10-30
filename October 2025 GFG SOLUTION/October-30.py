class Solution:
    def fill(self, g):
        m, n = len(g), len(g[0])
        for i in range(m):
            for j in range(n):
                if g[i][j] == 'O': g[i][j] = '-'
        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or g[i][j] != '-': return
            g[i][j] = 'O'
            dfs(i + 1, j); dfs(i - 1, j); dfs(i, j + 1); dfs(i, j - 1)
        for i in range(m): dfs(i, 0); dfs(i, n - 1)
        for j in range(n): dfs(0, j); dfs(m - 1, j)
        for i in range(m):
            for j in range(n):
                if g[i][j] == '-': g[i][j] = 'X'
