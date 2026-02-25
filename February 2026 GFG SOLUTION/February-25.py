class Solution:
    def longestSubarray(self, arr, k):
        mp = {}
        sum_val = ans = 0
        for i in range(len(arr)):
            sum_val += 1 if arr[i] > k else -1
            if sum_val > 0:
                ans = i + 1
            elif sum_val - 1 in mp:
                ans = max(ans, i - mp[sum_val - 1])
            if sum_val not in mp:
                mp[sum_val] = i
        return ans
