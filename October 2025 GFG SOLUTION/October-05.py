class Solution:
    def ratInMaze(self, m):
        res = []
        n = len(m)
        if not m[0][0] or not m[n-1][n-1]: return res
        self.solve(0, 0, m, n, "", res)
        return res
    
    def solve(self, i, j, m, n, p, res):
        if i == n-1 and j == n-1:
            res.append(p)
            return
        m[i][j] = 0
        if i+1 < n and m[i+1][j]: self.solve(i+1, j, m, n, p+'D', res)
        if j-1 >= 0 and m[i][j-1]: self.solve(i, j-1, m, n, p+'L', res)
        if j+1 < n and m[i][j+1]: self.solve(i, j+1, m, n, p+'R', res)
        if i-1 >= 0 and m[i-1][j]: self.solve(i-1, j, m, n, p+'U', res)
        m[i][j] = 1
