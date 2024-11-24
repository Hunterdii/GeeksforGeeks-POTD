#User function Template for python3

class Solution:
    #Function to find sum of all possible substrings of the given string.
    def sumSubstrings(self,s):
        mod = 10**9 + 7
        r = 1
        res = 0
        for i in range(len(s) - 1, -1, -1):
            res = (res + ((int(s[i]) * (i + 1) * r) % mod)) % mod
            r = (r * 10 + 1) % mod
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

import sys
sys.setrecursionlimit(10**6)

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        s = str(input())
        ob=Solution()
        print(ob.sumSubstrings(s))
# } Driver Code Ends
