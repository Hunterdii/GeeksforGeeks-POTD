class Solution:
    def countWays(self, s: str) -> int:
        if s[0] == '0': return 0
        prev2, prev1 = 1, 1
        for i in range(1, len(s)):
            curr = prev1 if s[i] != '0' else 0
            if s[i - 1] != '0' and int(s[i - 1:i + 1]) <= 26:
                curr += prev2
            prev2, prev1 = prev1, curr
        return prev1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        digits = input()
        ob = Solution()
        ans = ob.countWays(digits)
        print(ans)
        print("~")

# } Driver Code Ends
