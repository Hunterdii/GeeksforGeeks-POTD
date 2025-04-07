class Solution:
    def isCycle(self, V, edges):
        g = [[] for _ in range(V)]
        in_d = [0]*V
        for u, v in edges: g[u].append(v); in_d[v] += 1
        q = [i for i in range(V) if in_d[i] == 0]
        c = 0
        while q:
            u = q.pop(0); c += 1
            for v in g[u]:
                in_d[v] -= 1
                if in_d[v] == 0: q.append(v)
        return c != V


#{ 
 # Driver Code Starts
from collections import deque


def main():
    tc = int(input())
    for _ in range(tc):
        V = int(input())
        E = int(input())
        edges = []
        for _ in range(E):
            u, v = map(int, input().split())
            edges.append((u, v))

        obj = Solution()
        ans = obj.isCycle(V, edges)
        print("true" if ans else "false")


if __name__ == "__main__":
    main()

# } Driver Code Ends
