class Solution:
    def distinctSubseq(self, str):
        mod, res = 10**9 + 7, 1
        last = [0] * 26
        for c in str:
            idx = ord(c) - ord('a')
            cur = (2 * res - last[idx]) % mod
            last[idx] = res
            res = cur
        return res
