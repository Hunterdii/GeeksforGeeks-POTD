class Solution:
    def areIsomorphic(self, s1, s2):
        m1, m2 = {}, {}
        for c1, c2 in zip(s1, s2):
            if (c1 in m1 and m1[c1] != c2) or (c2 in m2 and m2[c2] != c1):
                return False
            m1[c1] = c2
            m2[c2] = c1
        return True
