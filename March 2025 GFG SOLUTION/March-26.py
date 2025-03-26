class Solution:
    def wordBreak(self, s, dictionary):
        d = set(dictionary)
        m = max((len(w) for w in dictionary), default=0)
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(n):
            if not dp[i]:
                continue
            for j in range(1, m + 1):
                if i + j <= n and s[i:i + j] in d:
                    dp[i + j] = True
        return dp[n]

#{ 
 # Driver Code Starts
if __name__ == '__main__':
    test_case = int(input())

    for _ in range(test_case):
        s = input().strip()
        dictionary = input().strip().split()
        ob = Solution()
        res = ob.wordBreak(s, dictionary)
        if res:
            print("true")
        else:
            print("false")
        print("~")
# } Driver Code Ends
