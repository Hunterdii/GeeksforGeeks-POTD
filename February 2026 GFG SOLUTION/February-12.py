class Solution:
    def maxMinHeight(self, a, k, w):
        def check(h):
            water, add = k, [0] * len(a)
            for i in range(len(a)):
                cur = a[i] + (add[i - 1] if i > 0 else 0)
                if i >= w:
                    cur -= add[i - w]
                if cur < h:
                    need = h - cur
                    if need > water:
                        return False
                    water -= need
                    add[i] = (add[i - 1] if i > 0 else 0) + need
                else:
                    add[i] = add[i - 1] if i > 0 else 0
            return True
        
        lo, hi = min(a), min(a) + k
        ans = lo
        while lo <= hi:
            mid = (lo + hi) // 2
            if check(mid):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1
        return ans
