
class Solution:
    def countWays(self, s1: str, s2: str) -> int:
        n, m = len(s1), len(s2)
        memo = [[-1] * (m + 1) for _ in range(n + 1)]
        mod = 10**9 + 7

        def dp(i, j):
            if j == 0:
                return 1  # s2 is empty, one way to match
            if i == 0:
                return 0  # s1 is empty, no way to match
            if memo[i][j] != -1:
                return memo[i][j]

            if s1[i - 1] == s2[j - 1]:
                memo[i][j] = (dp(i - 1, j - 1) + dp(i - 1, j)) % mod
            else:
                memo[i][j] = dp(i - 1, j) % mod

            return memo[i][j]

        return dp(n, m)
#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        s1 = (input())

        s2 = (input())

        obj = Solution()
        res = obj.countWays(s1, s2)

        print(res)

# } Driver Code Ends
