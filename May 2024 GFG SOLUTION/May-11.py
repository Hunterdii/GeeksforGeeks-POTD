#User function Template for python3

class Solution:
    def jugglerSequence(self, n):
        ans = []
        ans.append(n)

        while ans[-1] > 1:
            sqrt_n = (ans[-1] ** 0.5)
            next_term = int(sqrt_n) if ans[-1] % 2 == 0 else int(sqrt_n ** 3)
            ans.append(next_term)

        return ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())

        ob = Solution()
        arr = ob.jugglerSequence(n)
        for i in (arr):
            print(i, end=" ")
        print()

# } Driver Code Ends
