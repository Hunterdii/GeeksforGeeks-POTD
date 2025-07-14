class Solution:
    def cuts(self, s):
        if s[0] == '0': return -1
        n = len(s)
        powers = set()
        p = 1
        while p <= 10**9:
            powers.add(p)
            p *= 5
        dp = [n + 1] * (n + 1)
        dp[n] = 0
        for i in range(n - 1, -1, -1):
            if s[i] == '0': continue
            num = 0
            for j in range(i, n):
                num = (num << 1) + int(s[j])
                if num > 10**9: break
                if num in powers and dp[j + 1] <= n:
                    dp[i] = min(dp[i], 1 + dp[j + 1])
        return -1 if dp[0] > n else dp[0]
