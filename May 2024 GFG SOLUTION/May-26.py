#User function Template for python3
class Solution:
    def lcs(self, x, y):
        n, m = len(x), len(y)
        prev = [0] * (m + 1)
        curr = [0] * (m + 1)

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if x[i - 1] == y[j - 1]:
                    curr[j] = prev[j - 1] + 1
                else:
                    curr[j] = max(prev[j], curr[j - 1])
            prev, curr = curr, prev
        return prev[m]

    def findMinCost(self, x, y, costX, costY):
        length = self.lcs(x, y)
        return costX * (len(x) - length) + costY * (len(y) - length)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        X, Y, costX, costY = input().split()
        costX = int(costX)
        costY = int(costY)
        ob = Solution()
        ans = ob.findMinCost(X, Y, costX, costY)
        print(ans)

# } Driver Code Ends
