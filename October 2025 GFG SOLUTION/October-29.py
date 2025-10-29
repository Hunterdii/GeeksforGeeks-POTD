class Solution:
    def diameter(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        def bfs(src):
            dist = [-1] * V
            q = deque([src])
            dist[src] = 0
            far, maxD = src, 0
            while q:
                u = q.popleft()
                for v in adj[u]:
                    if dist[v] == -1:
                        dist[v] = dist[u] + 1
                        q.append(v)
                        if dist[v] > maxD:
                            maxD = dist[v]
                            far = v
            return far, maxD
        end1, _ = bfs(0)
        _, diam = bfs(end1)
        return diam
