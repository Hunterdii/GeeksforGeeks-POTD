
#User function Template for python3

class Solution:
    def searchMatrix(self, mat, x):
        n, m = len(mat), len(mat[0])
        l, r = 0, n * m - 1
        while l <= r:
            mid = (l + r) // 2
            val = mat[mid // m][mid % m]
            if val == x:
                return True
            if val < x:
                l = mid + 1
            else:
                r = mid - 1
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
        if ob.searchMatrix(matrix, x):
            print("true")
        else:
            print("false")
        print("~")
# } Driver Code Ends
