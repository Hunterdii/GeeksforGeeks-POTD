class Solution:
    def maximumProfit(self, prices):
        buyPrice = prices[0]
        maxProfit = 0

        for i in range(1, len(prices)):
            if prices[i] > buyPrice:
                maxProfit = max(maxProfit, prices[i] - buyPrice)
            else:
                buyPrice = prices[i]

        return maxProfit



#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())  # Read number of test cases
    for _ in range(t):
        # Read input and split it into a list of integers
        prices = list(map(int, input().split()))
        # Create a Solution object and calculate the result
        obj = Solution()
        result = obj.maximumProfit(prices)
        # Print the result
        print(result)

# } Driver Code Ends
