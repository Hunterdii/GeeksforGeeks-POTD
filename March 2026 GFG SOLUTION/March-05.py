class Solution:
    def longestKSubstr(self, s, k):
        mp = {}
        l = res = 0
        res = -1
        for r in range(len(s)):
            mp[s[r]] = mp.get(s[r], 0) + 1
            while len(mp) > k:
                mp[s[l]] -= 1
                if mp[s[l]] == 0:
                    del mp[s[l]]
                l += 1
            if len(mp) == k:
                res = max(res, r - l + 1)
        return res
