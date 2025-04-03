from collections import deque
class Solution:
    def orangesRotting(self, a):
        n, m, f, t = len(a), len(a[0]), 0, 0
        q = deque()
        for i in range(n):
            for j in range(m):
                if a[i][j] == 2:
                    q.append((i, j))
                elif a[i][j] == 1:
                    f += 1
        if not f: return 0
        d = [(1,0),(-1,0),(0,1),(0,-1)]
        while q:
            sz, ch = len(q), False
            for _ in range(sz):
                i, j = q.popleft()
                for di, dj in d:
                    x, y = i + di, j + dj
                    if x < 0 or y < 0 or x >= n or y >= m or a[x][y] != 1:
                        continue
                    a[x][y] = 2
                    q.append((x, y))
                    f -= 1
                    ch = True
            if ch: t += 1
        return t if f == 0 else -1

#{ 
 # Driver Code Starts
from queue import Queue

T = int(input())
for i in range(T):
    n = int(input())
    m = int(input())
    mat = []
    for _ in range(n):
        a = list(map(int, input().split()))
        mat.append(a)
    obj = Solution()
    ans = obj.orangesRotting(mat)
    print(ans)
    print("~")

# } Driver Code Ends
