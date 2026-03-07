class Solution:
    def minWindow(self, s, p):
        n, m = len(s), len(p)
        if n < m:
            return ""
        fp, fs = [0] * 256, [0] * 256
        for c in p:
            fp[ord(c)] += 1
        l = cnt = 0
        minLen, start = float('inf'), -1
        for r in range(n):
            fs[ord(s[r])] += 1
            if fp[ord(s[r])] and fs[ord(s[r])] <= fp[ord(s[r])]:
                cnt += 1
            while cnt == m:
                if r - l + 1 < minLen:
                    minLen = r - l + 1
                    start = l
                fs[ord(s[l])] -= 1
                if fp[ord(s[l])] and fs[ord(s[l])] < fp[ord(s[l])]:
                    cnt -= 1
                l += 1
        return "" if start == -1 else s[start:start + minLen]
