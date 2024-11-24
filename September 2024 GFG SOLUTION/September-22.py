#User function Template for python3

class Solution:
    def lps(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0

        lpsArr = [0] * n
        j = 0

        for i in range(1, n):
            while j > 0 and s[i] != s[j]:
                j = lpsArr[j - 1]
            if s[i] == s[j]:
                j += 1
            lpsArr[i] = j

        return lpsArr[n - 1]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.lps(s)
        print(answer)

# } Driver Code Ends
