class Solution:
    def findLargest(self, arr):
        s = sorted(map(str, arr), key=cmp_to_key(lambda x, y: -1 if x + y > y + x else 1))
        return '0' if s[0] == '0' else ''.join(s)
