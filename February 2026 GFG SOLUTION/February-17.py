class Solution:
    def overlapInt(self, arr):
        mx = max(a[1] for a in arr)
        diff = [0] * (mx + 2)
        for a in arr:
            diff[a[0]] += 1
            diff[a[1] + 1] -= 1
        res = cur = 0
        for x in diff:
            cur += x
            res = max(res, cur)
        return res
