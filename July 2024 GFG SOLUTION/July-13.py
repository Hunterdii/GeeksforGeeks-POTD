#User function Template for python3
from collections import defaultdict
from heapq import heappush, heappop
from typing import List


class Solution:

    def shortestPath(self, n: int, m: int,
                     edges: List[List[int]]) -> List[int]:
        par = [-1] * (n + 1)
        inf = float('inf')
        dist = [inf] * (n + 1)

        gp = defaultdict(list)

        for a, b, w in edges:
            gp[a].append((b, w))
            gp[b].append((a, w))

        pq = []
        heappush(pq, (0, 1, -1))

        while pq:
            w, node, p = heappop(pq)
            if w > dist[node]:
                continue
            dist[node] = w
            par[node] = p

            for adj, d in gp[node]:
                if dist[adj] > w + d:
                    dist[adj] = w + d
                    heappush(pq, (w + d, adj, node))

        if dist[n] == inf:
            return [-1]

        ans = []
        p = n
        while p != -1:
            ans.append(p)
            p = par[p]

        ans.append(dist[n])
        ans.reverse()

        return ans

#{ 
 # Driver Code Starts
from collections import defaultdict


def check(n, path, edges):
    gp = [{} for i in range(n + 1)]
    for u, v, w in edges:
        if v in gp[u]:
            gp[u][v] = min(gp[u][v], w)
        else:
            gp[u][v] = w

        if u in gp[v]:
            gp[v][u] = min(gp[v][u], w)
        else:
            gp[v][u] = w

    s = 0
    for i in range(2, len(path)):
        if path[i] not in gp[path[i - 1]]:
            return False
        s += gp[path[i - 1]][path[i]]

    return s == path[0]


if __name__ == "__main__":
    for _ in range(int(input())):
        n, m = map(int, input().split())
        edges = []
        for i in range(m):
            a, b, w = map(int, input().split())
            edges.append([a, b, w])

        obj = Solution()
        res = obj.shortestPath(n, m, edges)
        if res[0] == -1:
            print(-1)
        else:
            if check(n, res, edges):
                print(res[0])
            else:
                print(-2)

# } Driver Code Ends
