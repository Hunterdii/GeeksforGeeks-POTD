#User function Template for python3
class Solution:
    def numIslands(self, grid):
        n = len(grid)
        m = len(grid[0])
        ans = 0

        dx = [-1, 0, 1, 0, 1, -1, -1, 1]
        dy = [0, -1, 0, 1, 1, 1, -1, -1]

        def dfs(x, y):
            grid[x][y] = 0  
            for k in range(8):
                newX = x + dx[k]
                newY = y + dy[k]
                if is_valid(newX, newY) and grid[newX][newY] == 1:
                    dfs(newX, newY)

        def is_valid(x, y):
            return 0 <= x < n and 0 <= y < m

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    ans += 1
                    dfs(i, j)  

        return ans

#{ 
 # Driver Code Starts
# Driver code
if __name__ == "__main__":
    for _ in range(int(input())):
        n, m = map(int, input().strip().split())
        grid = []
        for i in range(n):
            grid.append([int(i) for i in input().strip().split()])
        obj = Solution()
        print(obj.numIslands(grid))

# } Driver Code Ends
