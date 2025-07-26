class Solution:
    def findMajority(self, arr):
        n, a, b, ca, cb = len(arr), 0, 1, 0, 0
        for x in arr:
            if x == a: ca += 1
            elif x == b: cb += 1
            elif ca == 0: a, ca = x, 1
            elif cb == 0: b, cb = x, 1
            else: ca, cb = ca - 1, cb - 1
        ca = cb = 0
        for x in arr:
            if x == a: ca += 1
            elif x == b: cb += 1
        res = []
        if ca > n // 3: res.append(a)
        if cb > n // 3 and a != b: res.append(b)
        return sorted(res)
