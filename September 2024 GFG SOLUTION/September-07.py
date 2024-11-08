#User function Template for python3

class Solution:
    def findNth(self, n):
        base9num = 0
        pos = 1
        
        while n > 0:
            base9num += (n % 9) * pos
            n //= 9
            pos *= 10
        
        return base9num

#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for i in range(0, t):
    n = int(input())
    obj = Solution()
    s = obj.findNth(n)
    print(s)

# } Driver Code Ends
