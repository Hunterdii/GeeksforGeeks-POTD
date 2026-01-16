class Solution:
    def minMen(self, arr):
        n = len(arr)
        v = []
        for i in range(n):
            if arr[i] != -1:
                v.append((max(0, i - arr[i]), min(n - 1, i + arr[i])))
        if not v: return -1
        v.sort()
        cnt, pos, i = 0, -1, 0
        while pos < n - 1:
            if i >= len(v) or v[i][0] > pos + 1: return -1
            reach = pos
            while i < len(v) and v[i][0] <= pos + 1:
                reach = max(reach, v[i][1])
                i += 1
            cnt += 1
            pos = reach
        return cnt
