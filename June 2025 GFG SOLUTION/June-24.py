class Solution:
    def maxSubseq(self, s, k):
        n, toRemove, res = len(s), k, []
        for c in s:
            while res and toRemove and res[-1] < c:
                res.pop()
                toRemove -= 1
            res.append(c)
        return ''.join(res[:n - k])
