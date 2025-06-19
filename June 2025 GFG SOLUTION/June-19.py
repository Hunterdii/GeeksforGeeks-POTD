class Solution:
    def caseSort(self, s):
        l, u = [0] * 26, [0] * 26
        for c in s:
            if c.islower():
                l[ord(c) - 97] += 1
            else:
                u[ord(c) - 65] += 1
        r, i, j = list(s), 0, 0
        for k in range(len(s)):
            if s[k].islower():
                while l[i] == 0:
                    i += 1
                r[k] = chr(i + 97)
                l[i] -= 1
            else:
                while u[j] == 0:
                    j += 1
                r[k] = chr(j + 65)
                u[j] -= 1
        return ''.join(r)
