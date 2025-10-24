class Solution:
    def isPossible(self, a, k):
        freq, need = {}, {}
        for x in a:
            freq[x] = freq.get(x, 0) + 1
        for x in a:
            if not freq[x]:
                continue
            freq[x] -= 1
            if need.get(x, 0):
                need[x] -= 1
                need[x + 1] = need.get(x + 1, 0) + 1
            else:
                for i in range(1, k):
                    if freq.get(x + i, 0) <= 0:
                        return False
                    freq[x + i] -= 1
                need[x + k] = need.get(x + k, 0) + 1
        return True
