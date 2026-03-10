class Solution:
    def largestSwap(self, s):
        a, last = list(s), [-1] * 10
        for i, c in enumerate(a): last[ord(c) - 48] = i
        for i in range(len(a)):
            for d in range(9, ord(a[i]) - 48, -1):
                if last[d] > i:
                    a[i], a[last[d]] = a[last[d]], a[i]
                    return ''.join(a)
        return s
