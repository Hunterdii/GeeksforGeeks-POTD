class Solution:
    def minCoins(self, coins, sum):
        dp = [float('inf')] * (sum + 1)
        dp[0] = 0
        for c in coins:
            for j in range(c, sum + 1):
                dp[j] = min(dp[j], dp[j - c] + 1)
        return -1 if dp[sum] == float('inf') else dp[sum]

#{ 
 # Driver Code Starts
#Initial Template for Python 3
#Position this line where user code will be pasted.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        k = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.minCoins(arr, k)
        print(res)
        print("~")
        t -= 1

# } Driver Code Ends
