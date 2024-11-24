#User function Template for python3


class Solution:
    def compareFrac(self, s):
        parts = s.split(", ")
        a, b = map(int, parts[0].split('/'))
        c, d = map(int, parts[1].split('/'))

        if a * d > b * c:
            return "{}/{}".format(a, b)
        elif a * d < b * c:
            return "{}/{}".format(c, d)
        else:
            return "equal"



#{ 
 # Driver Code Starts
#Initial Template for Python 3
import re

if __name__ == '__main__':
    ob = Solution()
    t = int(input())
    for _ in range(t):
        str = input()
        print(ob.compareFrac(str))

# } Driver Code Ends
