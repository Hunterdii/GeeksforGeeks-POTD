#User function Template for python3
class Solution:
    def countPS(self, s):
        n, res = len(s), 0
        for i in range(n):
            l, r = i, i
            while l >= 0 and r < n and s[l] == s[r]: res += 1; l -= 1; r += 1
            l, r = i, i + 1
            while l >= 0 and r < n and s[l] == s[r]: res += 1; l -= 1; r += 1
        return res - n

2)
class Solution:
    def countPS(self, s):
        n, res = len(s), 0
        dp = [[False] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = True
            for j in range(i + 1, n):
                if s[i] == s[j] and (j - i == 1 or dp[i + 1][j - 1]):
                    dp[i][j] = True
                    res += 1
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        s = input()

        solObj = Solution()

        print(solObj.countPS(s))

        print("~")
# } Driver Code Ends
