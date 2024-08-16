#User function Template for python3
class Solution:
    
    # Function to find the maximum number of cuts.
    def maximizeTheCuts(self, n, x, y, z):
        # Initialize dp array with -1. dp[i] will store the maximum number of cuts for length i.
        dp = [-1] * (n + 1)
        
        # Base case: If the length of the line is 0, no cuts are needed.
        dp[0] = 0
        
        # Iterate over all lengths from 1 to n
        for i in range(1, n + 1):
            # Check if it's possible to make a cut of length x
            if i >= x and dp[i - x] != -1:
                dp[i] = max(dp[i], dp[i - x] + 1)
                
            # Check if it's possible to make a cut of length y
            if i >= y and dp[i - y] != -1:
                dp[i] = max(dp[i], dp[i - y] + 1)
                
            # Check if it's possible to make a cut of length z
            if i >= z and dp[i - z] != -1:
                dp[i] = max(dp[i], dp[i - z] + 1)
        
        # If no segments could be made, return 0. Otherwise, return dp[n].
        return max(dp[n], 0)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())
    for tcs in range(t):
        n=int(input())
        x,y,z=[int(x) for x in input().split()]
        
        print(Solution().maximizeTheCuts(n,x,y,z))
# } Driver Code Ends