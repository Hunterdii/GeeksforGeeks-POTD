class Solution:
    def minWindow(self, s1, s2):
        m, n = len(s1), len(s2)
        start, minLen = -1, float('inf')
        i = j = 0
        while i < m:
            if s1[i] == s2[j]:
                j += 1
            if j == n:
                end = i
                j -= 1
                while j >= 0:
                    if s1[i] == s2[j]:
                        j -= 1
                    i -= 1
                i += 1
                j += 1
                if end - i + 1 < minLen:
                    minLen = end - i + 1
                    start = i
            i += 1
        return "" if start == -1 else s1[start:start + minLen]
