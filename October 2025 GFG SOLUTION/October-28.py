class Solution:
    def nearest(self, grid):
        n, m = len(grid), len(grid[0])
        dist = [[-1] * m for _ in range(n)]
        q = []
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    dist[i][j] = 0
                    q.append((i, j))
        dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]
        idx = 0
        while idx < len(q):
            x, y = q[idx]
            idx += 1
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if 0 <= nx < n and 0 <= ny < m and dist[nx][ny] == -1:
                    dist[nx][ny] = dist[x][y] + 1
                    q.append((nx, ny))
        return dist
