class Solution:
    def countBSTs(self, arr):
        n = len(arr)
        p = sorted((arr[i], i) for i in range(n))
        c = [0] * (n + 1)
        c[0] = c[1] = 1
        for i in range(2, n + 1):
            for j in range(i):
                c[i] += c[j] * c[i - j - 1]
        res = [0] * n
        for i in range(n):
            res[p[i][1]] = c[i] * c[n - i - 1]
        return res
