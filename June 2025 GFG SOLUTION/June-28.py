class Solution:
    def countLessEq(self, a, b):
        if not b: return [0]*len(a)
        m = max(b)
        cnt = [0]*(m+1)
        for x in b: cnt[x] += 1
        for i in range(1, m+1): cnt[i] += cnt[i-1]
        return [cnt[min(x, m)] for x in a]
