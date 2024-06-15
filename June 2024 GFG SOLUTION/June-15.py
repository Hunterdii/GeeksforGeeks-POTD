#User function Template for python3
class Solution:
    def __init__(self):
        self.a = [[1, 2, 3], [4, 5, 6], [7, 8, 9], [-1, 0, -1]]
        self.dp = [[[0 for _ in range(26)] for _ in range(3)] for _ in range(4)]
    
    def getCount(self, n):
        for i in range(4):
            for j in range(3):
                if self.a[i][j] != -1:
                    self.dp[i][j][1] = 1
        
        for length in range(2, n + 1):
            for i in range(4):
                for j in range(3):
                    if self.a[i][j] != -1:
                        self.dp[i][j][length] = self.dp[i][j][length - 1]
                        if j + 1 < 3 and self.a[i][j + 1] != -1:
                            self.dp[i][j][length] += self.dp[i][j + 1][length - 1]
                        if j - 1 >= 0 and self.a[i][j - 1] != -1:
                            self.dp[i][j][length] += self.dp[i][j - 1][length - 1]
                        if i + 1 < 4 and self.a[i + 1][j] != -1:
                            self.dp[i][j][length] += self.dp[i + 1][j][length - 1]
                        if i - 1 >= 0 and self.a[i - 1][j] != -1:
                            self.dp[i][j][length] += self.dp[i - 1][j][length - 1]
        
        ans = 0
        for i in range(4):
            for j in range(3):
                if self.a[i][j] != -1:
                    ans += self.dp[i][j][n]
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.getCount(n)
        print(ans)

# } Driver Code Ends
