class Solution:
    def pythagoreanTriplet(self, arr):
        s = set(x * x for x in arr)
        n = len(arr)
        for i in range(n):
            for j in range(i + 1, n):
                if arr[i]**2 + arr[j]**2 in s:
                    return True
        return False
