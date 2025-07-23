class Solution:
    def subarraySum(self, arr):
        n = len(arr)
        return sum(arr[i] * (i + 1) * (n - i) for i in range(n))
