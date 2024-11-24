#User function Template for python3
class Solution:
    def knapSack(self, W, wt, val):
        n = len(wt)
        K = [0] * (W + 1)
        
        for i in range(n):
            for w in range(W, wt[i] - 1, -1):
                K[w] = max(K[w], val[i] + K[w - wt[i]])
        
        return K[W]

#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        # n = int(input())
        W = int(input())
        val = list(map(int, input().strip().split()))
        wt = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.knapSack(W, wt, val))

# } Driver Code Ends
