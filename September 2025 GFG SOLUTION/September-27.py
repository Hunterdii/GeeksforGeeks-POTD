class Solution:
    def kBitFlips(self, a, k):
        n, flips, flip = len(a), 0, 0
        for i in range(n):
            if i >= k and a[i - k] > 1: flip ^= 1
            if (a[i] ^ flip) == 0:
                if i + k > n: return -1
                a[i] = 2
                flip ^= 1
                flips += 1
        return flips
