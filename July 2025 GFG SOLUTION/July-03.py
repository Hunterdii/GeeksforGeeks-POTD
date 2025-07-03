class Solution:
    def longestKSubstr(self, s, k):
        freq = [0] * 26
        i = cnt = maxi = 0
        for j in range(len(s)):
            if freq[ord(s[j]) - ord('a')] == 0:
                cnt += 1
            freq[ord(s[j]) - ord('a')] += 1
            while cnt > k:
                freq[ord(s[i]) - ord('a')] -= 1
                if freq[ord(s[i]) - ord('a')] == 0:
                    cnt -= 1
                i += 1
            if cnt == k:
                maxi = max(maxi, j - i + 1)
        return maxi if maxi > 0 else -1
