class Solution:
    def stringStack(self, pat, tar):
        i, j = len(pat) - 1, len(tar) - 1
        while i >= 0 and j >= 0:
            if pat[i] == tar[j]:
                i -= 1
                j -= 1
            else:
                i -= 2
        return j < 0
