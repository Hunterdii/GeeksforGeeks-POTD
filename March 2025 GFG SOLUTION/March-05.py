#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends

#User function Template for python3

class Solution:
    def longestStringChain(self, words):
        words.sort(key=len)
        dp = {}
        res = 1
        for w in words:
            dp[w] = 1
            for i in range(len(w)):
                pred = w[:i] + w[i+1:]
                if pred in dp:
                    dp[w] = max(dp[w], dp[pred] + 1)
            res = max(res, dp[w])
        return res


#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input())
    for _ in range (t):
        words = input().split()
        ob = Solution()
        res = ob.longestStringChain(words)
        print(res)
        print("~")
# } Driver Code Ends
