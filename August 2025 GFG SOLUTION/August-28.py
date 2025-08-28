class Solution:
    def maxOnes(self, arr, k):
        l = zeros = maxLen = 0
        for r in range(len(arr)):
            zeros += (arr[r] == 0)
            while zeros > k:
                zeros -= (arr[l] == 0)
                l += 1
            maxLen = max(maxLen, r - l + 1)
        return maxLen
