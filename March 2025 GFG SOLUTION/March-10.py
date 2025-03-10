class Solution:
    def editDistance(self, s1, s2):
        m, n = len(s1), len(s2)
        prev, curr = list(range(n + 1)), [0] * (n + 1)
        for i in range(1, m + 1):
            curr[0] = i
            for j in range(1, n + 1):
                curr[j] = prev[j-1] if s1[i-1] == s2[j-1] else 1 + min(prev[j-1], prev[j], curr[j-1])
            prev, curr = curr, prev
        return prev[n]


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s1 = input()
        s2 = input()
        ob = Solution()
        ans = ob.editDistance(s1, s2)
        print(ans)
        print("~")

# } Driver Code Ends
