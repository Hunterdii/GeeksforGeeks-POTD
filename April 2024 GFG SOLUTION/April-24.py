#Back-end complete function Template for Python 3

mod=10**9+7
def calculate():
    dp=[]
    for i in range(0,501):
        dp.append([0]*501)
    for i in range(0,501):
        dp[0][i]=1
        dp[i][0]=1
    dp[0][0]=1
    for i in range(1,501):
        for j in range(1,501):
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod
    return dp

dp=calculate()

class Solution:
    def ways(self, x,y):
        return dp[x][y]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t=int(input())
for _ in range(0,t):
    x,y=list(map(int,input().split()))
    ob = Solution()
    print(ob.ways(x,y))
# } Driver Code Ends
