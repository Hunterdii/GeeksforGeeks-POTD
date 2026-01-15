class Solution:
    def minCandy(self, arr):
        n, total, i = len(arr), len(arr), 1
        while i < n:
            if arr[i] == arr[i - 1]:
                i += 1
                continue
            peak = 0
            while i < n and arr[i] > arr[i - 1]:
                peak += 1
                total += peak
                i += 1
            valley = 0
            while i < n and arr[i] < arr[i - 1]:
                valley += 1
                total += valley
                i += 1
            total -= min(peak, valley)
        return total
