class Solution:
    def firstNonRepeating(self, s):
        freq = [0] * 26
        q = []
        res = []
        for c in s:
            freq[ord(c) - ord('a')] += 1
            q.append(c)
            while q and freq[ord(q[0]) - ord('a')] > 1:
                q.pop(0)
            res.append(q[0] if q else '#')
        return ''.join(res)
