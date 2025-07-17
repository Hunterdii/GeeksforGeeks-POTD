class Solution:
    def maxKPower(self, n, k):
        res = float('inf')
        i = 2
        while i * i <= k:
            if k % i == 0:
                cnt = 0
                while k % i == 0:
                    k //= i
                    cnt += 1
                fact = 0
                p = i
                while p <= n:
                    fact += n // p
                    p *= i
                res = min(res, fact // cnt)
            i += 1
        if k > 1:
            fact = 0
            p = k
            while p <= n:
                fact += n // p
                p *= k
            res = min(res, fact)
        return res if res != float('inf') else 0
