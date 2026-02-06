class Solution:
    def smallestDiff(self, a, b, c):
        a.sort()
        b.sort()
        c.sort()
        i = j = k = 0
        diff = float('inf')
        res = [0, 0, 0]
        while i < len(a) and j < len(b) and k < len(c):
            minVal = min(a[i], b[j], c[k])
            maxVal = max(a[i], b[j], c[k])
            midVal = a[i] + b[j] + c[k] - minVal - maxVal
            if maxVal - minVal < diff:
                diff = maxVal - minVal
                res = [maxVal, midVal, minVal]
            if minVal == a[i]: i += 1
            elif minVal == b[j]: j += 1
            else: k += 1
        return res
