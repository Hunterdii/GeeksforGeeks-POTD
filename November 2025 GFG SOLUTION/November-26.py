class Solution:
    def andInRange(self, l, r):
        while l < r: r &= r - 1
        return r
