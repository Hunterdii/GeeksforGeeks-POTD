class Solution:
    def minDifference(self, arr):
        mins = []
        for t in arr:
            h = int(t[:2])
            m = int(t[3:5])
            s = int(t[6:8])
            mins.append(h * 3600 + m * 60 + s)
        mins.sort()
        res = mins[0] + 86400 - mins[-1]
        for i in range(1, len(mins)):
            res = min(res, mins[i] - mins[i-1])
        return res
