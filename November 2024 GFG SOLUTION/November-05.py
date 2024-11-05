#User function Template for python3
def rotate(mat):
    n = len(mat)
    for i in range(n // 2):
        for j in range(i, n - i - 1):
            temp = mat[i][j]
            mat[i][j] = mat[n - j - 1][i]
            mat[n - j - 1][i] = mat[n - i - 1][n - j - 1]
            mat[n - i - 1][n - j - 1] = mat[j][n - i - 1]
            mat[j][n - i - 1] = temp


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        matrix = []
        for i in range(N):
            arr = [int(x) for x in input().strip().split()]
            matrix.append(arr)

        rotate(matrix)
        for i in range(N):
            for j in range(N):
                print(matrix[i][j], end=' ')
            print()
        print("~")

# } Driver Code Ends
