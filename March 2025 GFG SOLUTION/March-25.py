class Solution:
    def countWays(self, s):
        n = len(s)
        T, F = [[0] * n for _ in range(n)], [[0] * n for _ in range(n)]
        for i in range(0, n, 2): 
            T[i][i], F[i][i] = int(s[i] == 'T'), int(s[i] == 'F')
        for l in range(2, n, 2):
            for i in range(0, n - l, 2):
                for k, j in zip(range(i + 1, i + l, 2), [i + l] * (l // 2)):
                    lt, lf, rt, rf = T[i][k - 1], F[i][k - 1], T[k + 1][j], F[k + 1][j]
                    if s[k] == '&': 
                        T[i][j] += lt * rt
                        F[i][j] += lt * rf + lf * rt + lf * rf
                    elif s[k] == '|': 
                        T[i][j] += lt * rt + lt * rf + lf * rt
                        F[i][j] += lf * rf
                    else:  
                        T[i][j] += lt * rf + lf * rt
                        F[i][j] += lt * rt + lf * rf
        return T[0][n - 1]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = input().strip()
        print(Solution().countWays(s))
        print("~")

# } Driver Code Ends
