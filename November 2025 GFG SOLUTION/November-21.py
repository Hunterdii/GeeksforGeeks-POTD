class Solution:
    def shortestPath(self, V, a, b, edges):
        from heapq import heappush,heappop
        g=[[] for _ in range(V)]
        for u,v,w1,w2 in edges:
            g[u].append((v,w1,w2))
            g[v].append((u,w1,w2))
        d=[[float('inf')]*2 for _ in range(V)]
        d[a][0]=0
        pq=[(0,a,0)]
        while pq:
            dist,u,c=heappop(pq)
            if dist>d[u][c]:continue
            for v,w1,w2 in g[u]:
                if d[v][c]>dist+w1:
                    d[v][c]=dist+w1
                    heappush(pq,(d[v][c],v,c))
                if not c and d[v][1]>dist+w2:
                    d[v][1]=dist+w2
                    heappush(pq,(d[v][1],v,1))
        res=min(d[b][0],d[b][1])
        return -1 if res==float('inf') else res
