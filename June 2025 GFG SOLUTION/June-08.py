class Solution:
    def isSumString(self, s: str) -> bool:
        def add(a, b):
            return str(int(a) + int(b))
        
        def check(i, l1, l2):
            x, y = s[i:i + l1], s[i + l1:i + l1 + l2]
            if (len(x) > 1 and x[0] == '0') or (len(y) > 1 and y[0] == '0'):
                return False
            z = add(x, y)
            l3 = len(z)
            if i + l1 + l2 + l3 > len(s): return False
            if s[i + l1 + l2:i + l1 + l2 + l3] != z: return False
            if i + l1 + l2 + l3 == len(s): return True
            return check(i + l1, l2, l3)

        n = len(s)
        for l1 in range(1, n):
            for l2 in range(1, n - l1):
                if check(0, l1, l2): return True
        return False
