class Solution:
    def countStrings(self, s):
        m = [0]*26
        ans = 0
        for i, ch in enumerate(s):
            ans += i - m[ord(ch) - 97]
            m[ord(ch) - 97] += 1
        if any(x > 1 for x in m):
            ans += 1
        return ans
