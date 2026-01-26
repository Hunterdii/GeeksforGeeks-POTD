class Solution:
    def permuteDist(self, arr):
        from itertools import permutations
        return [list(p) for p in permutations(arr)]
