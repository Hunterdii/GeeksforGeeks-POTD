
class Solution:
    def findWinner(self, n: int, x: int, y: int) -> int:
        dp = [0] * (n + 1)
        dp[1] = 1

        for i in range(2, n + 1):
            if i >= 1 and dp[i - 1] == 0:
                dp[i] = 1
            elif i >= x and dp[i - x] == 0:
                dp[i] = 1
            elif i >= y and dp[i - y] == 0:
                dp[i] = 1
            else:
                dp[i] = 0

        return dp[n]


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n = int(input())

        x = int(input())

        y = int(input())

        obj = Solution()
        res = obj.findWinner(n, x, y)

        print(res)

# } Driver Code Ends
