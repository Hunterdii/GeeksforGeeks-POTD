class Solution:
    def cntSubarrays(self, arr, k):
        mp, s, cnt = {0: 1}, 0, 0
        for x in arr:
            s += x
            cnt += mp.get(s - k, 0)
            mp[s] = mp.get(s, 0) + 1
        return cnt
