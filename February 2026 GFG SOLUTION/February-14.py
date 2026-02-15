class Solution:
    def minTime(self, arr, k):
        l, r = max(arr), sum(arr)
        while l < r:
            m, cnt, s = l + (r - l) // 2, 1, 0
            ok = True
            for x in arr:
                if x > m:
                    ok = False
                    break
                if s + x > m:
                    cnt += 1
                    s = x
                else:
                    s += x
            if ok and cnt <= k:
                r = m
            else:
                l = m + 1
        return l
