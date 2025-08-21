class Solution:
    def maxMinDiff(self, a, k):
        a.sort()
        l, r, ans = 0, a[-1] - a[0], 0
        while l <= r:
            m = (l + r) // 2
            cnt, last = 1, a[0]
            for x in a[1:]:
                if x - last >= m:
                    cnt += 1
                    last = x
                    if cnt == k: break
            if cnt >= k:
                ans, l = m, m + 1
            else:
                r = m - 1
        return ans
