class Solution:
    def balanceSums(self, mat):
        n, max_sum, res = len(mat), 0, 0
        for i in range(n):
            sum_val = sum(mat[i])
            max_sum = max(sum_val, max_sum)
        for j in range(n):
            sum_val = sum(mat[i][j] for i in range(n))
            max_sum = max(sum_val, max_sum)
        for i in range(n):
            res += max_sum - sum(mat[i])
        return res
