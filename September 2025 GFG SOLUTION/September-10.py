class Solution:
    def largestSwap(self, s):
        s = list(s)
        n, l, r, maxIdx = len(s), -1, -1, len(s) - 1
        for i in range(n - 2, -1, -1):
            if s[i] > s[maxIdx]: maxIdx = i
            elif s[i] < s[maxIdx]: l, r = i, maxIdx
        if l != -1: s[l], s[r] = s[r], s[l]
        return ''.join(s)
