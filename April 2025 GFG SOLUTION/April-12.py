class Solution:
    def floodFill(self, A, sr, sc, nc):
        m, n, oc = len(A), len(A[0]), A[sr][sc]
        if oc == nc: return A
        q = [(sr, sc)]
        A[sr][sc] = nc
        d = [-1, 0, 1, 0, -1]
        while q:
            x, y = q.pop(0)
            for i in range(4):
                nx, ny = x + d[i], y + d[i+1]
                if 0 <= nx < m and 0 <= ny < n and A[nx][ny] == oc:
                    A[nx][ny] = nc
                    q.append((nx, ny))
        return A



#{ 
 # Driver Code Starts
import sys

sys.setrecursionlimit(10**7)

T = int(input())  # Read number of test cases
for i in range(T):
    n = int(input())
    m = int(input())

    # Reading the image matrix
    image = []
    for _ in range(n):
        image.append(list(map(int, input().split())))

    # Read starting row, column, and new color
    sr = int(input())
    sc = int(input())
    newColor = int(input())

    # Create an instance of the Solution class and apply floodFill
    obj = Solution()
    ans = obj.floodFill(image, sr, sc, newColor)

    for row in ans:
        print(" ".join(map(str, row)))
    print("~")

# } Driver Code Ends
