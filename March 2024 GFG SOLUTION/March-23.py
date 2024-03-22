#User function Template for python3

class Solution:
    def series(self, n):
        MOD = 10**9 + 7
        ans = []
        if n == 0:
            return ans  # Handle edge case
        
        prev, cur = 0, 1
        ans.append(prev)
        ans.append(cur)
        
        for i in range(2, n + 1):
            next_val = (prev + cur) % MOD
            ans.append(next_val)
            prev, cur = cur, next_val
        
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        result = ob.series(N)
        print(*result)
# } Driver Code Ends
