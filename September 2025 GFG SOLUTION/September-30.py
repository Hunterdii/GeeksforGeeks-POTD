class Solution:
    def binstr(self, n):
        res = []
        for i in range(1 << n):
            s = ""
            for j in range(n - 1, -1, -1):
                s += '1' if (i >> j) & 1 else '0'
            res.append(s)
        return res
