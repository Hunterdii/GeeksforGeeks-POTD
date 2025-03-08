class Solution:
    def longestPalindrome(self, s):
        start, max_len = 0, 0
        for i in range(len(s)):
            for l in [i, i + 1]:
                j = i
                while j >= 0 and l < len(s) and s[j] == s[l]: j, l = j - 1, l + 1
                if l - j - 1 > max_len: start, max_len = j + 1, l - j - 1
        return s[start:start + max_len]
        
        

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        S = input()

        ob = Solution()

        ans = ob.longestPalindrome(S)

        print(ans)
        print("~")
# } Driver Code Ends
