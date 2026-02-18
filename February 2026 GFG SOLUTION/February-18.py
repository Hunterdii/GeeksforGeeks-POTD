class Solution:
    def inversionCount(self, arr):
        def merge_sort(a):
            if len(a) <= 1: return a, 0
            m = len(a) // 2
            l, lc = merge_sort(a[:m])
            r, rc = merge_sort(a[m:])
            merged, cnt, i, j = [], lc + rc, 0, 0
            while i < len(l) and j < len(r):
                if l[i] <= r[j]: merged.append(l[i]); i += 1
                else: merged.append(r[j]); cnt += len(l) - i; j += 1
            return merged + l[i:] + r[j:], cnt
        _, ans = merge_sort(arr)
        return ans
