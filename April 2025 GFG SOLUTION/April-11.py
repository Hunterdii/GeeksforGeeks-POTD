class Solution:
    def dijkstra(self, V, edges, src):
        from heapq import heappush, heappop
        g = [[] for _ in range(V)]
        for u, v, w in edges:
            g[u].append((v, w))
        d = [float('inf')] * V
        d[src] = 0
        q = [(0, src)]
        while q:
            du, u = heappop(q)
            if du > d[u]: continue
            for v, w in g[u]:
                if du + w < d[v]:
                    d[v] = du + w
                    heappush(q, (d[v], v))
        return d



#{ 
 # Driver Code Starts
# Initial Template for Python 3
import sys
import heapq

# Position this line where user code will be pasted.


def main():
    t = int(input())
    for _ in range(t):
        V = int(input())
        E = int(input())
        edges = []
        for _ in range(E):
            u, v, w = map(int, input().split())
            edges.append([u, v, w])
            edges.append([v, u, w])  # Since the graph is undirected

        src = int(input())

        obj = Solution()
        res = obj.dijkstra(V, edges, src)

        print(" ".join(map(str, res)))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
