// This code is working in Some Scenario Mine is working (1115/1115) But in Some I have Received Feedbacks That it is having (1114/1115) So Not Sure of Working...
from typing import List

class Solution:
    def findShortestPath(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        visited = [[0] * n for _ in range(m)]
        vis = [[False] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0 and not vis[i][j]:
                    vis[i][j] = True
                    if i + 1 < m:
                        mat[i + 1][j] = 0
                        vis[i + 1][j] = True
                    if i - 1 >= 0:
                        mat[i - 1][j] = 0
                        vis[i - 1][j] = True
                    if j + 1 < n:
                        mat[i][j + 1] = 0
                        vis[i][j + 1] = True
                    if j - 1 >= 0:
                        mat[i][j - 1] = 0
                        vis[i][j - 1] = True
        
        arr = [float('inf')]
        
        for i in range(m):
            self.dfs(i, 0, mat, visited, 1, arr)
        
        if arr[0] == float('inf'):
            return -1
        return arr[0]
    
    def dfs(self, r, c, mat, visited, count, arr):
        if mat[r][c] == 0:
            return
        if c == len(mat[0]) - 1:
            if count < arr[0]:
                arr[0] = count
            return
        
        visited[r][c] = 1
        
        if r + 1 < len(mat) and mat[r + 1][c] == 1 and visited[r + 1][c] == 0:
            self.dfs(r + 1, c, mat, visited, count + 1, arr)
        if c + 1 < len(mat[0]) and mat[r][c + 1] == 1 and visited[r][c + 1] == 0:
            self.dfs(r, c + 1, mat, visited, count + 1, arr)
        if r - 1 >= 0 and mat[r - 1][c] == 1 and visited[r - 1][c] == 0:
            self.dfs(r - 1, c, mat, visited, count + 1, arr)
        if c - 1 >= 0 and mat[r][c - 1] == 1 and visited[r][c - 1] == 0:
            self.dfs(r, c - 1, mat, visited, count + 1, arr)
        
        visited[r][c] = 0

#{ 
 # Driver Code Starts
class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()



class IntMatrix:
    def __init__(self) -> None:
        pass
    def Input(self,n,m):
        matrix=[]
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix
    def Print(self,arr):
        for i in arr:
            for j in i:
                print(j,end=" ")
            print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        a=IntArray().Input(2)
        
        
        mat=IntMatrix().Input(a[0], a[1])
        
        obj = Solution()
        res = obj.findShortestPath(mat)
        
        print(res)
        

# } Driver Code Ends
