class Solution:
    def canServe(self, arr):
        f = t = 0
        for x in arr:
            if x == 5: f += 1
            elif x == 10:
                if not f: return False
                f -= 1; t += 1
            else:
                if t and f: t -= 1; f -= 1
                elif f >= 3: f -= 3
                else: return False
        return True
