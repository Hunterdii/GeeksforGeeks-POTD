#User function Template for python3

class Solution:
    def reversedBits(self, x):
        ans = 0
        for i in range(32):
            ans = (ans << 1) | (x & 1)  # Shift ans left by 1 and OR it with the least significant bit of x
            x >>= 1  # Shift x right by 1 to process the next bit
        return ans
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        X=int(input())
        
        ob = Solution()
        print(ob.reversedBits(X))
# } Driver Code Ends
