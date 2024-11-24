#User function Template for python3

class Solution:
    def FindCoverage(self, matrix):
        cnt = 0
        m, n = len(matrix), len(matrix[0])
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    if j < n - 1 and matrix[i][j + 1] == 1:
                        cnt += 1  # Right
                    if j > 0 and matrix[i][j - 1] == 1:
                        cnt += 1  # Left
                    if i < m - 1 and matrix[i + 1][j] == 1:
                        cnt += 1  # Down
                    if i > 0 and matrix[i - 1][j] == 1:
                        cnt += 1  # Up
        
        return cnt
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n, m = input().split()
        n = int(n)
        m = int(m)
        matrix = []
        for _ in range(n):
            matrix.append(list(map(int, input().split())))
        ob = Solution()
        ans = ob.FindCoverage(matrix)
        print(ans)

# } Driver Code Ends
