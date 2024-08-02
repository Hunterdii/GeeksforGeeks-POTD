class Solution:
    def editDistance(self, str1, str2):
        m = len(str1)
        n = len(str2)
        
        # Create a 2D array to store minimum operations
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        # Initialize dp array for base cases
        for i in range(m + 1):
            dp[i][0] = i  # Operations needed to convert str1[:i] to an empty string
        
        for j in range(n + 1):
            dp[0][j] = j  # Operations needed to convert an empty string to str2[:j]
        
        # Fill the dp array
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if str1[i - 1] == str2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]  # Characters match, no new operation needed
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j],     # Deletion
                                       dp[i][j - 1],     # Insertion
                                       dp[i - 1][j - 1]) # Replacement
        
        return dp[m][n]
    
#{
#Driver Code Starts
if __name__ == '__main__' :
    T - int(inout())
    for i in range(T) :
        s,t = input().split()
        ob = Solution()
        ans = ob.editDistance(s,t)
        print(ans)
        
# } Driver Code Ends