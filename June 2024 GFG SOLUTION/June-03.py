#User function Template for python3
class Solution:
    def numberOfConsecutiveOnes(self, n):
        MOD = 1000000007  # Removed underscores for compatibility
        if n == 1 or n == 2:
            return 1
        a, b = 1, 1
        res = 1
        for i in range(3, n + 1):
            c = (a + b) % MOD
            a, b = b, c
            res = (res * 2 + a) % MOD
        return res
#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):

        N = int(input())

        ob = Solution()
        print(ob.numberOfConsecutiveOnes(N))

# } Driver Code Ends
