class Solution:
    def countNumbers(self, n):
        from math import isqrt
        c, lim = 0, isqrt(n)
        spf = list(range(lim + 1))
        for i in range(2, isqrt(lim) + 1):
            if spf[i] == i:
                for j in range(i*i, lim + 1, i):
                    if spf[j] == j: spf[j] = i
        for i in range(2, lim + 1):
            p, q = spf[i], spf[i // spf[i]]
            if p * q == i and p != q and q != 1: c += 1
            elif spf[i] == i and i**8 <= n: c += 1
        return c
