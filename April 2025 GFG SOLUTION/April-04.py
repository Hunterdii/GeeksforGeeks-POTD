class Solution:
    def isCycle(self, V, edges):
        p = [-1]*V
        def f(x): return x if p[x]<0 else f(p[x])
        for u,v in edges:
            a, b = f(u), f(v)
            if a == b: return True
            if p[a] > p[b]: a,b = b,a
            p[a] += p[b]; p[b] = a
        return False

#{ 
 # Driver Code Starts
import sys
#Position this line where user code will be pasted.


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
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
