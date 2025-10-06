class Solution:
    def knightTour(self, n):
        b = [[-1] * n for _ in range(n)]
        dx, dy = [2, 1, -1, -2, -2, -1, 1, 2], [1, 2, 2, 1, -1, -2, -2, -1]
        def solve(x, y, s):
            if s == n * n: return True
            for i in range(8):
                nx, ny = x + dx[i], y + dy[i]
                if 0 <= nx < n and 0 <= ny < n and b[nx][ny] == -1:
                    b[nx][ny] = s
                    if solve(nx, ny, s + 1): return True
                    b[nx][ny] = -1
            return False
        b[0][0] = 0
        return b if solve(0, 0, 1) else []
