class Solution:
    def missingNumber(self, a):
        n = len(a)
        for i in range(n):
            while 0 < a[i] <= n and a[i] != a[a[i] - 1]:
                a[a[i] - 1], a[i] = a[i], a[a[i] - 1]
        for i in range(n):
            if a[i] != i + 1: return i + 1
        return n + 1

2)
class Solution:
    def missingNumber(self, a):
        n = len(a)
        for i in range(n):
            if a[i] <= 0: a[i] = n + 1
        for i in range(n):
            x = abs(a[i])
            if x <= n: a[x - 1] = -abs(a[x - 1])
        for i in range(n):
            if a[i] > 0: return i + 1
        return n + 1
