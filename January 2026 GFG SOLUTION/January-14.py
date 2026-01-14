class Solution:
    def catchThieves(self, arr, k):
        n, p, t, cnt = len(arr), 0, 0, 0
        while p < n and t < n:
            while p < n and arr[p] != 'P': p += 1
            while t < n and arr[t] != 'T': t += 1
            if p < n and t < n and abs(p - t) <= k:
                cnt += 1
                p += 1
                t += 1
            elif t < n and t < p: t += 1
            elif p < n and p < t: p += 1
        return cnt
