class Solution:
    def kthSmallest(self, matrix, k):
        n, l, r = len(matrix), matrix[0][0], matrix[-1][-1]
        while l < r:
            m = (l + r) // 2
            cnt, j = 0, n - 1
            for i in range(n):
                while j >= 0 and matrix[i][j] > m:
                    j -= 1
                cnt += j + 1
            if cnt < k:
                l = m + 1
            else:
                r = m
        return l
