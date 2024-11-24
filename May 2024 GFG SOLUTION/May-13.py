from typing import List

class Solution:
    def findNumberOfGoodComponent(self, e: int, v: int, edges: List[List[int]]) -> int:
        ans = 0
        visited = [0] * (v + 1)

        adj = [[] for _ in range(v + 1)]
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])

        for i in range(1, v + 1):
            if visited[i] == 0:
                vertices = 0
                edgesCount = 0

                stk = [i]
                visited[i] = 1

                while stk:
                    node = stk.pop()
                    vertices += 1
                    edgesCount += len(adj[node])

                    for neighbor in adj[node]:
                        if visited[neighbor] == 0:
                            stk.append(neighbor)
                            visited[neighbor] = 1

                edgesCount //= 2
                if edgesCount == (vertices * (vertices - 1)) // 2:
                    ans += 1

        return ans




#{ 
 # Driver Code Starts
class IntMatrix:

    def _init_(self) -> None:
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


if _name_ == "_main_":
    t = int(input())
    for _ in range(t):

        e = int(input())

        v = int(input())

        edges = IntMatrix().Input(e, 2)

        obj = Solution()
        res = obj.findNumberOfGoodComponent(e, v, edges)

        print(res)

# } Driver Code Ends
