class Solution:
    def count(self, s, k):
        freq = [0] * 26
        i = ans = distinct = 0
        for j in range(len(s)):
            if freq[ord(s[j]) - ord('a')] == 0:
                distinct += 1
            freq[ord(s[j]) - ord('a')] += 1
            while distinct > k:
                freq[ord(s[i]) - ord('a')] -= 1
                if freq[ord(s[i]) - ord('a')] == 0:
                    distinct -= 1
                i += 1
            ans += j - i + 1
        return ans

    def countSubstr(self, s, k):
        return self.count(s, k) - self.count(s, k - 1)
