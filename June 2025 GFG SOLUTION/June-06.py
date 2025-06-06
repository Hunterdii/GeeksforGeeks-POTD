class Solution:
    def search(self, pat, txt):
        d, q, m, n = 256, 101, len(pat), len(txt)
        ph = th = 0; h = 1; res = []
        for i in range(m - 1): h = (h * d) % q
        for i in range(m):
            ph = (d * ph + ord(pat[i])) % q
            th = (d * th + ord(txt[i])) % q
        for i in range(n - m + 1):
            if ph == th and txt[i:i + m] == pat:
                res.append(i + 1)
            if i < n - m:
                th = (d * (th - ord(txt[i]) * h) + ord(txt[i + m])) % q
                if th < 0: th += q
        return res
