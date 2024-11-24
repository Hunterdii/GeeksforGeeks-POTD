
from typing import List


import heapq

class Solution:
    def MinimumEffort(self, rows: int, columns: int, heights: List[List[int]]) -> int:
        pq = [(0, 0, 0)]  # (effort, row, column)
        dist = [[float('inf')] * columns for _ in range(rows)]
        dist[0][0] = 0
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]
        
        while pq:
            diff, row, col = heapq.heappop(pq)
            
            if row == rows - 1 and col == columns - 1:
                return diff
            
            for i in range(4):
                newr = row + dr[i]
                newc = col + dc[i]
                
                if 0 <= newr < rows and 0 <= newc < columns:
                    neweffort = max(abs(heights[row][col] - heights[newr][newc]), diff)
                    if neweffort < dist[newr][newc]:
                        dist[newr][newc] = neweffort
                        heapq.heappush(pq, (neweffort, newr, newc))
        return 0



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

        rows = int(input())

        columns = int(input())

        heights = IntMatrix().Input(rows, columns)

        obj = Solution()
        res = obj.MinimumEffort(rows, columns, heights)

        print(res)

# } Driver Code Ends
