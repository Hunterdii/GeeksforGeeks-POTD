class Solution:
    def floydWarshall(self, d):
        n, inf = len(d), 100000000
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if d[i][k] < inf and d[k][j] < inf and d[i][j] > d[i][k] + d[k][j]:
                        d[i][j] = d[i][k] + d[k][j]


#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        matrix = []
        for _ in range(n):
            matrix.append(list(map(int, input().split())))
        obj = Solution()
        obj.floydWarshall(matrix)
        for _ in range(n):
            for __ in range(n):
                print(matrix[_][__], end=" ")
            print()
        print("~")

# } Driver Code Ends
