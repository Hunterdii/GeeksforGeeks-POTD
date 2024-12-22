#User function Template for python3

class Solution:
    def matSearch(self, mat, x):
        r, c = 0, len(mat[0]) - 1
        while r < len(mat) and c >= 0:
            if mat[r][c] == x: return True
            elif mat[r][c] > x: c -= 1
            else: r += 1
        return False


#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    index = 1
    for _ in range(t):
        r = int(data[index])
        c = int(data[index + 1])
        index += 2
        matrix = []
        for i in range(r):
            row = list(map(int, data[index:index + c]))
            matrix.append(row)
            index += c
        x = int(data[index])
        index += 1
        ob = Solution()
        if ob.matSearch(matrix, x):
            print("true")
        else:
            print("false")
        print("~")
# } Driver Code Ends
