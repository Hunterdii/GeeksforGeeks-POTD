class Solution:
    def getCount(self, n):
        p = [[1]*3 for _ in range(4)]
        p[3][0] = p[3][2] = 0
        d = [(0,0),(0,1),(0,-1),(1,0),(-1,0)]
        for _ in range(2,n+1):
            c = [[0]*3 for _ in range(4)]
            for i in range(4):
                for j in range(3):
                    if i==3 and j in (0,2): continue
                    for dx,dy in d:
                        x,y = i+dx,j+dy
                        if 0<=x<4 and 0<=y<3: c[i][j] += p[x][y]
            p = c
        return sum(sum(r) for r in p)
