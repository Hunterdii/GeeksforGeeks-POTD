class Solution:
    def getLPSLength(self, s):
        n, j, lps = len(s), 0, [0] * len(s)
        i = 1
        while i < n:
            if s[i] == s[j]:
                j += 1
                lps[i] = j
                i += 1
            elif j:
                j = lps[j - 1]
            else:
                i += 1
        return lps[-1]
