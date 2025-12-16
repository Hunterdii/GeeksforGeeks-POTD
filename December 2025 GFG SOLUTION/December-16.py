
class Solution:
    def areRotations(self, s1, s2):
        # If lengths differ, they can't be rotations
        if len(s1) != len(s2):
            return False
        
        # s2 must appear inside s1+s1 if it's a rotation
        return s2 in (s1 + s1)
