#User function Template for python3

class Solution:
    def longestSubstring(self, s, n):
        max_len = 0
        ans = "-1"
        i = j = 0

        while i < n and j < n:
            sub_string = s[i:j + 1]

            if s.find(sub_string, j + 1) != -1:
                length = len(sub_string)
                if length > max_len:
                    max_len = length
                    ans = sub_string
            else:
                i += 1
            j += 1
        
        return ans

 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        S=input()
        
        ob = Solution()
        print(ob.longestSubstring(S , N))
# } Driver Code Ends
