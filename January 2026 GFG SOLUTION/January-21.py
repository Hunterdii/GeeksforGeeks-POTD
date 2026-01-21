class Solution:
    def calculateSpan(self, arr):
        n = len(arr)
        res = []
        s = []
        for i in range(n):
            while s and arr[s[-1]] <= arr[i]: s.pop()
            res.append(i + 1 if not s else i - s[-1])
            s.append(i)
        return res
