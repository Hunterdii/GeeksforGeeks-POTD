class Solution:
    def substrCount(self, s, k):
        if k > len(s): return 0
        cnt = [0]*26
        ans = d = 0
        for i in range(k-1):
            if cnt[ord(s[i])-97] == 0: d += 1
            cnt[ord(s[i])-97] += 1
        for i in range(k-1, len(s)):
            if cnt[ord(s[i])-97] == 0: d += 1
            cnt[ord(s[i])-97] += 1
            if d == k - 1: ans += 1
            idx = ord(s[i-k+1])-97
            cnt[idx] -= 1
            if cnt[idx] == 0: d -= 1
        return ans
