class Solution:
    def countTriangles(self, a):
        a.sort()
        c, n = 0, len(a)
        for k in range(n - 1, 1, -1):
            i, j = 0, k - 1
            while i < j:
                if a[i] + a[j] > a[k]:
                    c += j - i
                    j -= 1
                else:
                    i += 1
        return c
