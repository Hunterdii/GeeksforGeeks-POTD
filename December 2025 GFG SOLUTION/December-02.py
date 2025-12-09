class Solution:
    def maxScore(self, s, jumps):
        n = len(s)
        jumps += [[chr(c), chr(c)] for c in range(97, 123)]
        nxt = [[-1] * 26 for _ in range(n)]
        last = [-1] * 26
        for i in range(n - 1, -1, -1):
            nxt[i] = last[:]
            last[ord(s[i]) - 97] = i
        ch = [[] for _ in range(26)]
        for u, v in jumps:
            ch[ord(u) - 97].append(ord(v))
        pre = [0] * (n + 1)
        for i in range(n):
            pre[i + 1] = pre[i] + ord(s[i])
        dp = [0] * n
        for i in range(n - 2, -1, -1):
            for c in ch[ord(s[i]) - 97]:
                j = nxt[i][c - 97]
                if j != -1:
                    dp[i] = max(dp[i], pre[j] - pre[i + (c == ord(s[i]))] + dp[j])
        return dp[0]
