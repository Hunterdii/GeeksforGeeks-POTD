class Solution:
    def knapsack(self, W, val, wt):
        dp = [0] * (W + 1)
        for i in range(len(wt)):
            for j in range(W, wt[i] - 1, -1):
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]])
        return dp[W]


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    test_cases = int(input())
    for _ in range(test_cases):
        capacity = int(input())
        values = list(map(int, input().strip().split()))
        weights = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.knapsack(capacity, values, weights))
        print("~")
# } Driver Code Ends
