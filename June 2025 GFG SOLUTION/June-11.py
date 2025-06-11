class Solution:
    def findLength(self, color, radius):
        j = -1
        for i, (c, r) in enumerate(zip(color, radius)):
            if j >= 0 and c == color[j] and r == radius[j]:
                j -= 1
            else:
                j += 1
                color[j], radius[j] = c, r
        return j + 1
