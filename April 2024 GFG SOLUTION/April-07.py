#User function Template for python3
class Solution:
    def maxDotProduct(self, n, m, a, b):
        dp = [[-1] * (m + 1) for _ in range(n + 1)]
        return self.solve(n, m, a, b, dp)

    def solve(self, n, m, a, b, dp):
        if m == 0:
            return 0
        if n < m:
            return float('-inf')
        if dp[n][m] != -1:
            return dp[n][m]
        t2 = self.solve(n - 1, m, a, b, dp)
        t3 = a[n - 1] * b[m - 1] + self.solve(n - 1, m - 1, a, b, dp)
        dp[n][m] = max(t2, t3)
        return dp[n][m]

 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n,m = input().split()
		n,m = int(n),int(m)
		a = [int(x) for x in input().split()]
		b = [int(x) for x in input().split()]
		ob = Solution()
		ans = ob.maxDotProduct(n,m,a,b)
		print(ans)
# } Driver Code Ends
