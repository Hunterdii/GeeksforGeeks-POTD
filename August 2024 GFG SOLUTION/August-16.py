#User function Template for python3
class Solution:
    def maximizeTheCuts(self, n, x, y, z):
        dp = [-1] * (n + 1)
        dp[0] = 0

        cuts = [x, y, z]

        for i in range(1, n + 1):
            for cut in cuts:
                if i >= cut and dp[i - cut] != -1:
                    dp[i] = max(dp[i], dp[i - cut] + 1)

        return dp[n] if dp[n] != -1 else 0



#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__':
    t=int(input())
    for tcs in range(t):
        n=int(input())
        x,y,z=[int(x) for x in input().split()]
        
        print(Solution().maximizeTheCuts(n,x,y,z))
# } Driver Code Ends
