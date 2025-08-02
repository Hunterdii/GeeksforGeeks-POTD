class Solution:
    def longestSubarray(self, arr, k):
        mp, ans, s = {0: -1}, 0, 0
        for i, x in enumerate(arr):
            s += -1 if x <= k else 1
            if s > 0: ans = i + 1
            elif s - 1 in mp: ans = max(ans, i - mp[s - 1])
            mp.setdefault(s, i)
        return ans
