class Solution:
    def findMoves(self, c, p):
        c.sort()
        p.sort()
        return sum(abs(x - y) for x, y in zip(c, p))
