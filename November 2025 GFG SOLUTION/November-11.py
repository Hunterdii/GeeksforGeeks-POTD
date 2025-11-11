class Solution:
    def minSuperSeq(self, s1, s2):
        m, n = len(s1), len(s2)
        prev, curr = [0] * (n + 1), [0] * (n + 1)
        for j in range(n + 1): prev[j] = j
        for i in range(1, m + 1):
            curr[0] = i
            for j in range(1, n + 1):
                curr[j] = 1 + prev[j - 1] if s1[i - 1] == s2[j - 1] else 1 + min(prev[j], curr[j - 1])
            prev = curr[:]
        return prev[n]
