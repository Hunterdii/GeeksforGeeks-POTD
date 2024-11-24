#User function Template for python3
class Solution:
    def firstElement(self, n):
        mod = 1000000007
        if n <= 2:
            return 1
        one, two = 1, 1
        for i in range(3, n + 1):
            sum = (one + two) % mod
            one = two
            two = sum
        return sum

 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = int(input())
        
        ob = Solution()
        print(ob.firstElement(n))
# } Driver Code Ends
