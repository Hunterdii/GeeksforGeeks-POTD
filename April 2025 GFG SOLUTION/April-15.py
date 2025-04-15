class Solution:
    def bellmanFord(self, V, edges, src):
        dist = [int(1e8)] * V
        dist[src] = 0
        for _ in range(V - 1):
            for u, v, w in edges:
                if dist[u] < 1e8 and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
        for u, v, w in edges:
            if dist[u] < 1e8 and dist[u] + w < dist[v]:
                return [-1]
        return dist


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        V = int(input())
        E = int(input())
        edges = []
        for i in range(E):
            u, v, w = map(int, input().strip().split())
            edges.append([u, v, w])
        S = int(input())
        ob = Solution()

        res = ob.bellmanFord(V, edges, S)
        for i in res:
            print(i, end=" ")
        print()
        print("~")

# } Driver Code Ends
