class Solution:
    def countPS(self, s):
        n, ans = len(s), 0
        def go(l, r):
            nonlocal ans
            while l >= 0 and r < n and s[l] == s[r]:
                ans += 1
                l -= 1
                r += 1
        for i in range(n):
            go(i-1, i+1)
            go(i, i+1)
        return ans
