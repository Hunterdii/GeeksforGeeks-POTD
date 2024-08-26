# your task is to complete this function
# function should return True/False or 1/0
# str1: pattern
# str2: text
class Solution:
    def wildCard(self, pattern, string):
        m = len(string)
        n = len(pattern)
        dp = [0] * (n + 1)
        dp[0] = 1

        for j in range(1, n + 1):
            if pattern[j - 1] == '*':
                dp[j] = dp[j - 1]

        for i in range(1, m + 1):
            new_dp = [0] * (n + 1)
            for j in range(1, n + 1):
                if pattern[j - 1] == '?' or pattern[j - 1] == string[i - 1]:
                    new_dp[j] = dp[j - 1]
                elif pattern[j - 1] == '*':
                    new_dp[j] = dp[j] or new_dp[j - 1]
            dp = new_dp

        return dp[n]
#{ 
 # Driver Code Starts
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        pattern = input().strip()
        string = input().strip()
        if Solution().wildCard(pattern, string):
            print(1)
        else:
            print(0)

# } Driver Code Ends
