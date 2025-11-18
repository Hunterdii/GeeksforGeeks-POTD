from heapq import heappush, heappop

class Solution:
    def minCostPath(self, mat):
        n, m = len(mat), len(mat[0])
        dist = [[float('inf')] * m for _ in range(n)]
        pq = [(0, 0, 0)]
        dist[0][0] = 0
        dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
        while pq:
            d, x, y = heappop(pq)
            if x == n - 1 and y == m - 1: return d
            if d > dist[x][y]: continue
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if 0 <= nx < n and 0 <= ny < m:
                    nd = max(d, abs(mat[nx][ny] - mat[x][y]))
                    if nd < dist[nx][ny]:
                        dist[nx][ny] = nd
                        heappush(pq, (nd, nx, ny))
        return dist[n - 1][m - 1]
