#User function Template for python3

class Solution:
    def FindExitPoint(self, n, m, matrix):
        i, j, k = 0, 0, 0
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        while i >= 0 and j >= 0 and i < n and j < m:
            if matrix[i][j] == 1:
                matrix[i][j] = 0
                k = (k + 1) % 4
            i += dx[k]
            j += dy[k]
        return [i - dx[k], j - dy[k]]

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
        ans = ob.FindExitPoint(n, m, matrix)
        for _ in ans:
            print(_, end=" ")
        print()

# } Driver Code Ends
