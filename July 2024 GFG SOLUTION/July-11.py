from typing import List, Set
from collections import defaultdict, deque

class Solution:
    def __init__(self):
        self.directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    def bfs(self, grid: List[List[int]], i: int, j: int, index: int) -> int:
        n = len(grid)
        queue = deque([(i, j)])
        grid[i][j] = index
        area_size = 0

        while queue:
            x, y = queue.popleft()
            area_size += 1
            for dx, dy in self.directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1:
                    grid[nx][ny] = index
                    queue.append((nx, ny))

        return area_size

    def findNeighbours(self, grid: List[List[int]], i: int, j: int) -> Set[int]:
        n = len(grid)
        neighbors = set()
        for dx, dy in self.directions:
            ni, nj = i + dx, j + dy
            if 0 <= ni < n and 0 <= nj < n and grid[ni][nj] > 1:
                neighbors.add(grid[ni][nj])
        return neighbors

    def MaxConnection(self, grid: List[List[int]]) -> int:
        n = len(grid)
        index = 2
        area = defaultdict(int)
        max_area = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    area[index] = self.bfs(grid, i, j, index)
                    max_area = max(max_area, area[index])
                    index += 1
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    neighbors = self.findNeighbours(grid, i, j)
                    potential_area = 1 + sum(area[idx] for idx in neighbors)
                    max_area = max(max_area, potential_area)

        return max_area


#{ 
 # Driver Code Starts
class IntMatrix:

    def __init__(self) -> None:
        pass

    def Input(self, n, m):
        matrix = []
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix

    def Print(self, arr):
        for i in arr:
            for j in i:
                print(j, end=" ")
            print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n = int(input())

        grid = IntMatrix().Input(n, n)

        obj = Solution()
        res = obj.MaxConnection(grid)

        print(res)

# } Driver Code Ends
