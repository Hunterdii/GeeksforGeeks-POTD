#User function Template for python3

class Solution:
    def sumMatrix(self, n, q):
        if q > 2 * n:
            return 0
        elif q <= n + 1:
            return q - 1
        else:
            return 2 * n - q + 1
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, q = map(int, input().split())

        ob = Solution()
        print(ob.sumMatrix(n, q))

# } Driver Code Ends
