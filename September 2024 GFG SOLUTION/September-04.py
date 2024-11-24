#User function Template for python3

class Solution:
    def nthStair(self, n):
        if n == 0:
            return 1
        if n == 1:
            return 1
        
        prev2 = 1
        prev1 = 1
        current = 1
        
        for i in range(2, n + 1):
            current = prev2 + 1
            prev2 = prev1
            prev1 = current
        
        return current

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		ob = Solution();
		ans = ob.nthStair(n)
		print(ans)
# } Driver Code Ends
