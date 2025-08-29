class Solution:
    def smallestWindow(self, s, p):
        m, n = len(s), len(p)
        if m < n: return ""
        need = [0] * 256
        for c in p: need[ord(c)] += 1
        missing, start, min_start, min_len = n, 0, 0, float('inf')
        for end in range(m):
            if need[ord(s[end])] > 0: missing -= 1
            need[ord(s[end])] -= 1
            while missing == 0:
                if end - start + 1 < min_len:
                    min_len = end - start + 1
                    min_start = start
                need[ord(s[start])] += 1
                if need[ord(s[start])] > 0: missing += 1
                start += 1
        return "" if min_len == float('inf') else s[min_start:min_start + min_len]
