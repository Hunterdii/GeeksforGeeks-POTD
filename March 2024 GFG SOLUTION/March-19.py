#User function Template for python3

class Solution:
    def root(self, i, parent):
        while parent[i] != i:
            parent[i] = parent[parent[i]]
            i = parent[i]
        return i

    def Union(self, a, b, parent, sz):
        ra = self.root(a, parent)
        rb = self.root(b, parent)
        if ra == rb:
            return sz[ra] * sz[ra]
        if sz[ra] < sz[rb]:
            ra, rb = rb, ra
        self.ans += sz[ra] * sz[rb]
        parent[rb] = ra
        sz[ra] += sz[rb]
        return self.ans

    def maximumWeight(self, n, edges, q, queries):
        self.ans = 0
        parent = [i for i in range(n + 1)]
        sz = [1] * (n + 1)
        res = []
        edges.sort(key=lambda x: x[2])
        mp = {}
        for edge in edges:
            a, b, c = edge
            mp[c] = self.Union(a, b, parent, sz)
        for query in queries:
            val = max(filter(lambda x: x <= query, mp.keys()), default=None)
            if val is None:
                res.append(0)
            else:
                res.append(mp[val])
        return res

        



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if _name_ == '_main_': 
    t = int(input())
    for _ in range(t):
        n = int(input())

        edges = [[0 for j in range(3)] for i in range(n-1)]
        for i in range(n-1):
            input_line = [int(x) for x in input().strip().split()]       
            for j in range (3):
                edges[i][j]=input_line[j]

        q = int(input())
        queries = list(map(int, input().strip().split()))

        ob = Solution()
        ans = ob.maximumWeight(n, edges, q, queries)
        for i in ans:
            print(i,end=" ")
        print()


# } Driver Code Ends
