#User function Template for python3


# class Solution:
#     def longestPalinSubseq(self, s):
#         n = len(s)
#         prev = [0] * (n + 1)
#         curr = [0] * (n + 1)

#         for i in range(1, n + 1):
#             for j in range(1, n + 1):
#                 if s[i - 1] == s[n - j]:
#                     curr[j] = 1 + prev[j - 1]
#                 else:
#                     curr[j] = max(prev[j], curr[j - 1])
#             prev, curr = curr, prev

#         return prev[n]

class Solution:
    def longestPalinSubseq(self, s):
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = 2 + dp[i + 1][j - 1]
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return dp[0][n - 1]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        ob = Solution()
        ans = ob.longestPalinSubseq(s)
        print(ans)
        print("~")
# } Driver Code Ends
