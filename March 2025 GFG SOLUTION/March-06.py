class Solution:
    def lcs(self, s1, s2):
        m, n = len(s1), len(s2)
        dp = [0] * (n + 1)
        for i in range(m):
            prev = 0
            for j in range(n):
                temp = dp[j + 1]
                dp[j + 1] = prev + 1 if s1[i] == s2[j] else max(dp[j + 1], dp[j])
                prev = temp
        return dp[n]
        
#{ 
 # Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        s1 = str(input())  # Take first string as input
        s2 = str(input())  # Take second string as input
        ob = Solution()
        # Call the lcs function and print the result
        print(ob.lcs(s1, s2))
        print("~")

# } Driver Code Ends
