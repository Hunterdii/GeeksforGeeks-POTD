class Solution:
    def equalSumSpan(self, a1, a2):
        mp = {0: -1}
        diff = maxLen = 0
        for i in range(len(a1)):
            diff += a1[i] - a2[i]
            if diff in mp:
                maxLen = max(maxLen, i - mp[diff])
            else:
                mp[diff] = i
        return maxLen
