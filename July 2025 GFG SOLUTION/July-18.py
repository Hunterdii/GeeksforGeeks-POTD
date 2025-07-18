class Solution:
    def lcmTriplets(self, n):
        return n if n < 3 else n * (n - 1) * (n - 2) if n & 1 else \
               n * (n - 1) * (n - 3) if n % 3 else (n - 1) * (n - 2) * (n - 3)
