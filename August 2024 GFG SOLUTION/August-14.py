# User function Template for python3

class Solution:
    def longestCommonSubstr(self, str1, str2):
        n, m = len(str1), len(str2)
        res = 0

        prev = [0] * (m + 1)
        curr = [0] * (m + 1)

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if str1[i - 1] == str2[j - 1]:
                    curr[j] = 1 + prev[j - 1]
                    res = max(res, curr[j])
                else:
                    curr[j] = 0
            prev = curr[:]
        
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S1 = input().strip()
        S2 = input().strip()
        ob = Solution()
        print(ob.longestCommonSubstr(S1, S2))

# } Driver Code Ends