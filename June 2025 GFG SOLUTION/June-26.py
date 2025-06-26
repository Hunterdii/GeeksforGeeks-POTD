class Solution:
    def minValue(self, s, k):
        f = [0] * 26
        for c in s: f[ord(c) - 97] += 1
        m = max(f)
        b = [0] * (m + 1)
        for x in f: b[x] += x > 0
        while k and m:
            if b[m] <= k: k -= b[m]; b[m - 1] += b[m]; b[m] = 0; m -= 1
            else: b[m] -= k; b[m - 1] += k; k = 0
        return sum(i * i * b[i] for i in range(1, m + 1))
