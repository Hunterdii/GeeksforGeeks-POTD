class Solution:
    def assignHole(self, m, h):
        m.sort()
        h.sort()
        return max(abs(a - b) for a, b in zip(m, h))
