class Solution:
    def palinParts(self, s):
        n = len(s)
        d = [[False]*n for _ in range(n)]
        for i in range(n): d[i][i] = True
        for i in range(n-1): d[i][i+1] = s[i] == s[i+1]
        for l in range(3, n+1):
            for i in range(n-l+1):
                j = i + l - 1
                d[i][j] = s[i] == s[j] and d[i+1][j-1]
        r = []
        def b(i, c):
            if i == n: r.append(c[:]); return
            for j in range(i, n):
                if d[i][j]:
                    c.append(s[i:j+1])
                    b(j+1, c)
                    c.pop()
        b(0, [])
        return r
