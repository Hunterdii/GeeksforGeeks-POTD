#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def smallestNumber(self, s, d):
        if s > 9 * d:
            return "-1"

        result = ['0'] * d
        s -= 1

        for i in range(d - 1, -1, -1):
            if s > 9:
                result[i] = '9'
                s -= 9
            else:
                result[i] = chr(ord('0') + s)
                s = 0

        result[0] = chr(ord(result[0]) + 1)  
        return ''.join(result)
#{ 
 # Driver Code Starts.
# Position this line where user code will be pasted.

import sys
import math
input = sys.stdin.read
data = input().split()

t = int(data[0])
index = 1

for _ in range(t):
    s = int(data[index])
    d = int(data[index + 1])
    index += 2
    ob = Solution()
    print(ob.smallestNumber(s, d))

# } Driver Code Ends
