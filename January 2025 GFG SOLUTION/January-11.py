#User function Template for python3
class Solution:
    def longestUniqueSubstr(self, s):
        last_seen = [-1] * 128  
        max_length = 0
        start = 0

        for end, char in enumerate(s):
            start = max(start, last_seen[ord(char)] + 1)
            last_seen[ord(char)] = end
            max_length = max(max_length, end - start + 1)

        return max_length

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        s = input()

        solObj = Solution()

        ans = solObj.longestUniqueSubstr(s)

        print(ans)

        print("~")
# } Driver Code Ends
