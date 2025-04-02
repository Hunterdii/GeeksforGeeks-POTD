#User function Template for python3
from collections import deque

class Solution:
    def bfs(self, adj):
        r, v = [], [False] * len(adj)
        q = deque([0])
        v[0] = True
        while q:
            i = q.popleft()
            r.append(i)
            for j in adj[i]:
                if not v[j]:
                    v[j] = True
                    q.append(j)
        return r
        
 # Driver Code Starts
import sys


#Position this line where user code will be pasted.
def main():
    tc = int(sys.stdin.readline().strip())

    for _ in range(tc):
        V = int(sys.stdin.readline().strip())  # Number of vertices
        adj = []  # Adjacency list

        for _ in range(V):
            input_line = sys.stdin.readline().strip()
            node = list(map(int, input_line.split())) if input_line else []
            adj.append(node)

        obj = Solution()
        ans = obj.bfs(adj)
        print(" ".join(map(str, ans)))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
