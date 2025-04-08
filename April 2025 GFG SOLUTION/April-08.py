class Solution:
    def dfs(self, g, vis, u):
        vis[u] = 1
        for v in g[u]:
            if not vis[v]: self.dfs(g, vis, v)

    def isBridge(self, V, edges, c, d):
        g = [[] for _ in range(V)]
        for u, v in edges:
            if (u, v) != (c, d) and (v, u) != (c, d):
                g[u].append(v)
                g[v].append(u)
        vis = [0] * V
        self.dfs(g, vis, c)
        return not vis[d]



#{ 
 # Driver Code Starts
import sys

sys.setrecursionlimit(10**7)
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        V = int(input())
        E = int(input())
        adj = [[] for _ in range(V)]
        edges = []

        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)
            edges.append([u, v])

        c = int(input())
        d = int(input())

        obj = Solution()
        l = obj.isBridge(V, edges, c, d)

        if l:
            print("true")
        else:
            print("false")

        print("~")

# } Driver Code Ends
