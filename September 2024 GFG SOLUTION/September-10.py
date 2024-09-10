#User function Template for python3
class Solution:
    def dfs(self, node, adj, visited):
        visited[node] = True
        for u in adj[node]:
            if not visited[u]:
                self.dfs(u, adj, visited)

    def isConnected(self, adj, indegree):
        visited = [False] * 26
        start = -1
        
        for i in range(26):
            if indegree[i] > 0:
                start = i
                break
        
        if start == -1:
            return True
        
        self.dfs(start, adj, visited)
        
        for i in range(26):
            if indegree[i] > 0 and not visited[i]:
                return False
        
        return True

    def isCircle(self, arr):
        N = len(arr)
        adj = [[] for _ in range(26)]
        adjr = [[] for _ in range(26)]
        indegree = [0] * 26
        outdegree = [0] * 26
        
        for word in arr:
            u = ord(word[0]) - ord('a')
            v = ord(word[-1]) - ord('a')
            adj[u].append(v)
            adjr[v].append(u)
            outdegree[u] += 1
            indegree[v] += 1

        for i in range(26):
            if indegree[i] != outdegree[i]:
                return 0

        if not self.isConnected(adj, indegree):
            return 0

        if not self.isConnected(adjr, outdegree):
            return 0
        
        return 1



#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = input().split()

        ob = Solution()
        print(ob.isCircle(A))

# } Driver Code Ends
