class Solution:
    def countPairs(self, a, b, x):
        r1 = c1 = 0
        r2, c2 = len(b) - 1, len(b[0]) - 1
        cnt = 0
        while r1 < len(a) and r2 >= 0:
            s = a[r1][c1] + b[r2][c2]
            if s == x:
                cnt += 1
                c1 += 1
                c2 -= 1
            elif s < x:
                c1 += 1
            else:
                c2 -= 1
            if c1 == len(a[0]):
                c1 = 0
                r1 += 1
            if c2 < 0:
                c2 = len(b[0]) - 1
                r2 -= 1
        return cnt
