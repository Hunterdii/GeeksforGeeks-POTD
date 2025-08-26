class Solution:
    def isSubSeq(self, s1, s2):
        i = 0
        for c in s2:
            if i < len(s1) and s1[i] == c:
                i += 1
        return i == len(s1)
