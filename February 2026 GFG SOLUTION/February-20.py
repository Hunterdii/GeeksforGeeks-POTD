class Solution:
    def findLargest(self, arr):
        from functools import cmp_to_key
        s = list(map(str, arr))
        s.sort(key=cmp_to_key(lambda a, b: -1 if a + b > b + a else 1))
        return '0' if s[0] == '0' else ''.join(s)
