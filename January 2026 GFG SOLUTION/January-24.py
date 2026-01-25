class Solution:
    def josephus(self, n, k):
        pos = 0
        for i in range(2, n + 1): pos = (pos + k) % i
        return pos + 1
