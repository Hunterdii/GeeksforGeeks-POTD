class Solution:
    def possibleWords(self, arr):
        res = [""]
        keys = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        for d in arr:
            if d < 2 or d > 9: continue
            res = [s + c for s in res for c in keys[d]]
        return res
