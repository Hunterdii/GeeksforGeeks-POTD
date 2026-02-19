class Solution:
    def missingRange(self, arr, low, high):
        present = [False] * (high - low + 1)
        for x in arr:
            if low <= x <= high:
                present[x - low] = True
        return [low + i for i in range(high - low + 1) if not present[i]]
