class Solution: 
    def maxProfit(self, jobs):
        jobs.sort()
        n = len(jobs)
        dp = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            l, r, nxt = i + 1, n - 1, n
            while l <= r:
                m = (l + r) // 2
                if jobs[m][0] >= jobs[i][1]:
                    nxt = m
                    r = m - 1
                else:
                    l = m + 1
            dp[i] = max(jobs[i][2] + dp[nxt], dp[i + 1])
        return dp[0]
