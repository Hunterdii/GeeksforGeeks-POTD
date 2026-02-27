class Solution:
    def findClosestPair(self, arr1, arr2, x):
        i, j, min_diff = 0, len(arr2) - 1, float('inf')
        res = []
        while i < len(arr1) and j >= 0:
            s, diff = arr1[i] + arr2[j], abs(arr1[i] + arr2[j] - x)
            if diff < min_diff:
                min_diff, res = diff, [arr1[i], arr2[j]]
            i, j = (i + 1, j) if s < x else (i, j - 1)
        return res
