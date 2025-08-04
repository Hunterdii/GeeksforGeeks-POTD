class Solution:
    def maxRectSum(self, mat):
        m, n, res = len(mat), len(mat[0]), float('-inf')
        for l in range(n):
            temp = [0] * m
            for r in range(l, n):
                for i in range(m):
                    temp[i] += mat[i][r]
                sum_val, max_sum = 0, temp[0]
                for x in temp:
                    sum_val = max(x, sum_val + x)
                    max_sum = max(max_sum, sum_val)
                res = max(res, max_sum)
        return res
