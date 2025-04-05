class Solution:
    def numIslands(self, g):
        n, m, ans = len(g), len(g[0]), 0
        def dfs(i, j):
            if i < 0 or j < 0 or i >= n or j >= m or g[i][j]=='W': return
            g[i][j] = 'W'
            for a in (-1,0,1):
                for b in (-1,0,1):
                    dfs(i+a, j+b)
        for i in range(n):
            for j in range(m):
                if g[i][j]=='L':
                    ans += 1
                    dfs(i, j)
        return ans

#{ 
 # Driver Code Starts
# Driver code
if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input().strip())
        m = int(input().strip())
        grid = [input().strip().split() for _ in range(n)]

        obj = Solution()
        print(obj.numIslands(grid))
        print("~")

# } Driver Code Ends
