# Your task is to complete this function

# Your task is to complete this function

class Solution:
    def matrixDiagonally(self, mat):
        diagonalMap = {}
        n = len(mat)
        
        for i in range(n):
            for j in range(n):
                diagonalIndex = i + j
                if diagonalIndex % 2 == 0:
                    diagonalMap[(diagonalIndex, j)] = mat[i][j]
                else:
                    diagonalMap[(diagonalIndex, i)] = mat[i][j]
        
        diagonalOrder = [diagonalMap[key] for key in sorted(diagonalMap.keys())]
        return diagonalOrder




#{ 
 # Driver Code Starts
# Driver Program
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        matrix = [[0 for i in range(n[0])]for j in range(n[0])]
        k=0
        for i in range(n[0]):
            for j in range(n[0]):
                matrix[i][j] = arr[k]
                k+=1
        a = Solution().matrixDiagonally(matrix)
        for x in a:
            print(x,end=' ')
        print('')
# Contributed by: Harshit Sidhwa
# } Driver Code Ends
