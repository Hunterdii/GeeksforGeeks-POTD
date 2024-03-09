class Solution:
    def firstElementKTime(self, n, k, a):
        fdh = {}
        for i in range(n):
            if fdh.get(a[i]) and fdh[a[i]] + 1 == k:
                return a[i]
            elif fdh.get(a[i]):
                fdh[a[i]] += 1
            else:
                fdh[a[i]] = 1
        return -1
