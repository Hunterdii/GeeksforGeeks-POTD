class Solution:
    def getLongestPrefix(self, s):
        n, l, r, ans = len(s), 0, 0, -1
        z = [0] * n
        for i in range(1, n):
            if i <= r:
                z[i] = min(r - i + 1, z[i - l])
            while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                z[i] += 1
            if i + z[i] - 1 > r:
                l, r = i, i + z[i] - 1
            if z[i] == n - i:
                ans = i
        return ans
