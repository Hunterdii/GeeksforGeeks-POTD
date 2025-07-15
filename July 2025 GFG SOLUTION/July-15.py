class Solution:
    def divby13(self, s):
        r = 0
        for c in s:
            r = (r * 10 + int(c)) % 13
        return r == 0
