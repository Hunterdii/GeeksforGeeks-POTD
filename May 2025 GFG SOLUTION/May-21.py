class Solution(object):
    def kthSmallest(self, m, n, k):
        l, r = 1, m * n
        while l < r:
            mid = (l + r) // 2
            cnt = sum(min(n, mid // i) for i in range(1, m + 1))
            if cnt < k: l = mid + 1
            else: r = mid
        return l
