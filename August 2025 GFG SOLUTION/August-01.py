class Solution:
    def countBalanced(self, arr):
        mp, s, res = {0: 1}, 0, 0
        for string in arr:
            s += sum(1 if c in 'aeiou' else -1 for c in string)
            res += mp.get(s, 0)
            mp[s] = mp.get(s, 0) + 1
        return res
