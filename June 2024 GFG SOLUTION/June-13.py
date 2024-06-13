#User function Template for python3

class Solution:
    def padovanSequence(self, n):
        if n <= 2:
            return 1

        MOD = 1000000007
        pPrevPrev, pPrev, pCurr = 1, 1, 1
        for _ in range(3, n + 1):
            pNext = (pPrevPrev + pPrev) % MOD
            pPrevPrev, pPrev, pCurr = pPrev, pCurr, pNext

        return pCurr

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ob = Solution()
        print(ob.padovanSequence(n))

# } Driver Code Ends
