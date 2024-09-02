import heapq

class Solution:
    def minimumCostPath(self, grid):
        n = len(grid)
        m = len(grid[0])
        dp = [[float('inf')] * m for _ in range(n)]
        pq = []
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        
        dp[0][0] = grid[0][0]
        heapq.heappush(pq, (dp[0][0], 0, 0))
        
        while pq:
            dist, x, y = heapq.heappop(pq)
            
            if dist > dp[x][y]:
                continue
                
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                
                if 0 <= nx < n and 0 <= ny < m:
                    newDist = dp[x][y] + grid[nx][ny]
                    if newDist < dp[nx][ny]:
                        dp[nx][ny] = newDist
                        heapq.heappush(pq, (newDist, nx, ny))
        
        return dp[n-1][m-1]

#{ 
 # Driver Code Starts

T=int(input())
for i in range(T):
	n = int(input())
	grid = []
	for _ in range(n):
		a = list(map(int, input().split()))
		grid.append(a)
	obj = Solution()
	ans = obj.minimumCostPath(grid)
	print(ans)

# } Driver Code Ends
