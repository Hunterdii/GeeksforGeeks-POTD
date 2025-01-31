#User function Template for python3
class Solution:
    def solveSudoku(self, b):
        r, c, box = [0] * 9, [0] * 9, [0] * 9
        for i in range(9):
            for j in range(9):
                if b[i][j]:
                    m = 1 << b[i][j]
                    r[i] |= m; c[j] |= m; box[i // 3 * 3 + j // 3] |= m
        self.solve(b, r, c, box, 0, 0)
    
    def solve(self, b, r, c, box, i, j):
        if i == 9: return True
        if j == 9: return self.solve(b, r, c, box, i + 1, 0)
        if b[i][j]: return self.solve(b, r, c, box, i, j + 1)
        for num in range(1, 10):
            m = 1 << num
            idx = i // 3 * 3 + j // 3
            if r[i] & m or c[j] & m or box[idx] & m: continue
            b[i][j] = num; r[i] |= m; c[j] |= m; box[idx] |= m
            if self.solve(b, r, c, box, i, j + 1): return True
            b[i][j] = 0; r[i] &= ~m; c[j] &= ~m; box[idx] &= ~m
        return False
        
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    index = 1

    for _ in range(t):
        matrix = []
        n = 9
        for i in range(n):
            row = list(map(int, data[index:index + n]))
            matrix.append(row)
            index += n
        obj = Solution()
        obj.solveSudoku(matrix)
        for i in range(n):
            for j in range(n):
                print(matrix[i][j], end=" ")
            print()
        print("~")

# } Driver Code Ends
