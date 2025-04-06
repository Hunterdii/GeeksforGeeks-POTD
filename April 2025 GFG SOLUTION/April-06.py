
from collections import deque

class Solution:
    def topoSort(self, V, edges):
        g = [[] for _ in range(V)]
        in_deg = [0] * V
        res = []
        for u, v in edges:
            g[u].append(v)
            in_deg[v] += 1
        q = deque(i for i in range(V) if in_deg[i] == 0)
        while q:
            u = q.popleft()
            res.append(u)
            for v in g[u]:
                in_deg[v] -= 1
                if in_deg[v] == 0:
                    q.append(v)
        return res

#{ 
 # Driver Code Starts
# Driver Program

import sys

sys.setrecursionlimit(10**6)


def check(graph, N, res):
    if N != len(res):
        return False
    map = [0] * N
    for i in range(N):
        map[res[i]] = i
    for i in range(N):
        for v in graph[i]:
            if map[i] > map[v]:
                return False
    return True


def main():
    tc = int(input())
    for _ in range(tc):
        V = int(input())
        E = int(input())
        edges = []
        adj = [[] for i in range(V)]
        for _ in range(E):
            u, v = map(int, input().split())
            edges.append((u, v))
            adj[u].append(v)

        obj = Solution()
        res = obj.topoSort(V, edges)

        if check(adj, V, res):
            print("true")
        else:
            print("false")
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
