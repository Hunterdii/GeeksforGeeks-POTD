#User function Template for python3

class Solution:
    def dfs(self, adj):
        r, v = [], [False] * len(adj)
        def go(i):
            v[i] = True
            r.append(i)
            for j in adj[i]:
                if not v[j]:
                    go(j)
        for i in range(len(adj)):
            if not v[i]:
                go(i)
        return r


#{ 
 # Driver Code Starts
import sys
#Position this line where user code will be pasted.


def main():
    tc = int(sys.stdin.readline().strip())

    for _ in range(tc):
        V = int(sys.stdin.readline().strip())
        adj = []

        for _ in range(V):
            input_line = sys.stdin.readline().strip()
            node = list(map(int, input_line.split())) if input_line else []
            adj.append(node)

        obj = Solution()
        ans = obj.dfs(adj)
        print(" ".join(map(str, ans)))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
