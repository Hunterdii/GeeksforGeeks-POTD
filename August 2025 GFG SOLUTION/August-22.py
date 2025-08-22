import bisect
class Solution:
    def median(self, mat):
        n, m = len(mat), len(mat[0])
        lo = min(row[0] for row in mat)
        hi = max(row[m-1] for row in mat)
        req = (n * m + 1) // 2
        while lo < hi:
            mid = (lo + hi) // 2
            cnt = sum(bisect.bisect_right(row, mid) for row in mat)
            if cnt < req:
                lo = mid + 1
            else:
                hi = mid
        return lo
